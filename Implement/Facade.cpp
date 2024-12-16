#include "../Header/Facade.h"

bool isLeapYear(int year) {
    // A year is a leap year if it's divisible by 4, but not divisible by 100 unless divisible by 400.
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int day, int month, int year) {
    // Check if the year is positive
    if (year < 1) {
        return false;
    }

    // Array of the number of days in each month for a non-leap year
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust February for leap years
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;  // February has 29 days in a leap year
    }

    // Check if the month is valid (1-12)
    if (month < 1 || month > 12) {
        return false;
    }

    // Check if the day is valid for the given month
    if (day < 1 || day > daysInMonth[month - 1]) {
        return false;
    }

    return true;
}

LibraryFacade::LibraryFacade() {
    ifstream file("DATA/lastID.txt");
    int staticID;
    file >> staticID;
    Member::setStaticID(staticID);
    file.close();

    // Load members
    file.open("DATA/human.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name;
        int day, month, year, id;

        getline(ss, name, ',');
        ss >> day;
        ss.ignore(); 
        ss >> month; 
        ss.ignore();
        ss >> year;
        ss.ignore();
        ss >> id;
        members.push_back(new Member(name, day, month, year, id));
    }
    file.close();

    // Load books
    file.open("DATA/storage.txt");
    while (getline(file, line)) {
        stringstream ss(line);
        string type;
        getline(ss, type, ',');
        BookFactory* factory = nullptr;
        if (type == "novel") 
            factory = new NovelFactory();
        else if (type == "textbook") 
            factory = new TextBookFactory();
        if (factory) {
            books.push_back(factory->createBook(line));
            delete factory;
        }
    }
    file.close();

    // Load borrowed books
    for (Book* book : books) {
        if (book->getIsBorrowed()) {
            int id = book->getIdBorrower();
            for (Member* member : members) {
                if (member->getID() == id) {
                    member->borrowBook(book);
                    break;
                }
            }
        }
    }
}

LibraryFacade::~LibraryFacade() {
    ofstream file("DATA/storage.txt");
    for (Book* book : books) { 
        file << book->getType() << "," << book->getTitle()
        << "," << book->getAuthor() << "," << book->getYear() 
        << ",";

        if (book->getType() == "novel")     
            file << book->getGenre();
        if (book->getType() == "textbook")
            file << book->getSubject();

        if (book->getIsBorrowed()) 
            file << "," << "borrowed," << book->getIdBorrower() << endl;
        else 
            file << ",available" << endl;
        delete book;
    }
    file.close();

    file.open("DATA/human.txt");
    for (Member* member : members) {
        file << member->getFullname() << "," << member->getDateOfBirth() 
        << "," << member->getID() << endl;
        delete member;
    }
    file.close();

    file.open("DATA/lastID.txt");
    file << Member::getStaticID();
    file.close();
}

void LibraryFacade::search() {
    // type = 1: search by title
    // type = 2: search by author
    // type = 3: search by type
    searchStrategy* strategy = nullptr;
    string str;
    int type = 0;
    cout << "Choose search type: " << endl;
    cout << "1. Search by title" << endl;
    cout << "2. Search by author" << endl;
    cout << "3. Search by type" << endl;
    cout << "Choose an option: ";
    cin >> type;
    cout << "Enter search key: ";
    cin.ignore();
    getline(cin, str);
    if (type == 1)
        strategy = new searchByTitle();
    else if (type == 2)
        strategy = new searchByAuthor();
    else if (type == 3)
        strategy = new searchByType();
    else {
        cout << "Invalid search type" << endl;
        return;
    }
    vector<Book*> res = strategy->searchBook(books, str);
    delete strategy;
    if (res.empty()) 
        cout << "No result found" << endl;
    else
        for (Book* book : res) 
            book->displayInfo();
}

void LibraryFacade::displayAllBooks() {
    if (books.empty()) 
        cout << "No books in library" << endl;
    else
        for (Book* book : books) {
            book->displayInfo();
        }
}

void LibraryFacade::displayAllMembers() {
    if (members.empty()) 
        cout << "No members in library" << endl;
    else
        for (Member* member : members) 
            member->displayInfo();
}

void LibraryFacade::addBook() {
    int option = 0;
    string type;
    BookFactory* factory = nullptr;
    cout << "Enter type\n";
    cout << "1. Novel\n";
    cout << "2. TextBook\n";
    cout << "Enter option: ";
    cin >> option;
    cin.ignore();
    if (option == 1) 
        factory = new NovelFactory();
    else if (option == 2)
        factory = new TextBookFactory();
    else {
        cout << "Invalid\n";
        return;
    }

    books.push_back(factory->createBook());
    delete factory;
}

void LibraryFacade::addMember() {
    string fullname;
    int day, month, year;
    cout << "Enter fullname: ";
    cin.ignore();
    getline(cin, fullname);
    cout << "Enter day of birth: ";
    cin >> day;
    cout << "Enter month of birth: ";
    cin >> month;
    cout << "Enter year of birth: ";
    cin >> year;
    if (!isValidDate(day, month, year)) {
        cout << "Invalid date" << endl;
        return;
    }
    members.push_back(new Member(fullname, day, month, year));
}

bool LibraryFacade::borrowBook() {
    int ID;
    string title;
    searchStrategy* strategy = new searchByTitle();

    cout << "Enter member ID: ";
    cin >> ID;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, title);

    vector<Book*> res = strategy->searchBook(books, title);
    delete strategy;
    if (res.empty()) {
        cout << "No result found" << endl;
        return false;
    }
    Book* book = res[0];
    if (book->getIsBorrowed()) {
        cout << "Book is borrowed" << endl;
        return false;
    }
    for (Member* member : members) {
        if (member->getID() == ID) {
            member->borrowBook(book);
            return true;
        }
    }
    return false;
}

void LibraryFacade::returnBook() {
    int ID;
    string title;
    searchStrategy* strategy = new searchByTitle();

    cout << "Enter member ID: ";
    cin >> ID;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, title);

    vector<Book*> res = strategy->searchBook(books, title);
    delete strategy;
    if (res.empty()) {
        cout << "No result found" << endl;
        return;
    }
    Book* book = res[0];
    if (!book->getIsBorrowed()) {
        cout << "Book is not borrowed" << endl;
        return;
    }
    for (Member* member : members) {
        if (member->getID() == ID) {
            member->returnBook(book);
            return;
        }
    }
    cout << "Member not found" << endl;
}