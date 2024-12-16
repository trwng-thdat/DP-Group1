#include "../Header/Factory.h"

Book* NovelFactory::createBook() {
    Novel* book = new Novel();
    book->setInformation();
    return book;
}

Book* NovelFactory::createBook(string line) {
    string type, name, author, genre, state;
    int year, id;

    stringstream ss(line);
    getline(ss, type, ',');
    getline(ss, name, ',');
    getline(ss, author, ',');
    ss >> year;
    ss.ignore(1); // Ignore comma after year
    getline(ss, genre, ',');
    getline(ss, state, ',');

    // Trim spaces
    auto trim = [](std::string& str) {
        str.erase(0, str.find_first_not_of(" \t"));
        str.erase(str.find_last_not_of(" \t") + 1);
    };

    trim(type);
    trim(name);
    trim(author);
    trim(genre);
    trim(state);

    bool borrowed = (state == "available") ? false : true;
    if (borrowed) {
        ss >> id;
        return new Novel(name, author, year, genre, borrowed, id);
    }

    return new Novel(name, author, year, genre, borrowed);
}

Book* TextBookFactory::createBook() {
    TextBook* book = new TextBook();
    book->setInformation();
    return book;
}

Book* TextBookFactory::createBook(string line) {
    string type, name, author, subject, state;
    int year;

    stringstream ss(line);
    getline(ss, type, ',');
    getline(ss, name, ',');
    getline(ss, author, ',');
    ss >> year;
    ss.ignore(1); // Ignore comma after year
    getline(ss, subject, ',');
    getline(ss, state, ',');

    // Trim spaces
    auto trim = [](std::string& str) {
        str.erase(0, str.find_first_not_of(" \t"));
        str.erase(str.find_last_not_of(" \t") + 1);
    };

    trim(type);
    trim(name);
    trim(author);
    trim(subject);
    trim(state);

    bool borrowed = (state == "available") ? false : true;

    if (borrowed) {
        int id;
        ss >> id;
        return new TextBook(name, author, year, subject, borrowed, id);
    }

    return new TextBook(name, author, year, subject, borrowed);
}

Human* MemberFactory::createHuman(string line) {
    // Format: type,fullname,day,month,year
    string type, fullname;
    int day, month, year;

    stringstream ss(line);
    getline(ss, type, ',');
    getline(ss, fullname, ',');
    ss >> day;
    ss.ignore(1); // Ignore comma after day
    ss >> month;
    ss.ignore(1); // Ignore comma after month
    ss >> year;

    // Trim spaces
    auto trim = [](std::string& str) {
        str.erase(0, str.find_first_not_of(" \t"));
        str.erase(str.find_last_not_of(" \t") + 1);
    };

    trim(type);
    trim(fullname);

    return new Member(fullname, day, month, year);
}