#include "../Header/Member.h"

int Member::staticID = 0;

Member::Member() : Human(), ID(0) {}
Member::Member(string fullname, int day, int month, int year) : 
Human(fullname, day, month, year) { ID = ++staticID; }
Member::Member(string fullname, int day, int month, int year, int ID) :
Human(fullname, day, month, year), ID(ID) {}
Member::Member(const Member& member) :
Human(member.fullname, member.day, member.month, member.year), ID(member.ID) {}
Member::~Member() {}

void Member::setStaticID(int ID) {staticID = ID;}
int Member::getStaticID() {return staticID;}
int Member::getID() {return ID;}
void Member::displayInfo() {
    cout << "ID: " << ID << endl;
    cout << "Fullname: " << fullname << endl;
    cout << "Date of birth: " << getDateOfBirth() << endl;
    cout << "Borrowed books: " << borrowedBooks.size() << endl;
}
void Member::borrowBook(Book* book) {
    borrowedBooks.push_back(book);
    book->setIsBorrowed(true);    
    book->setIdBorrower(ID);
}

void Member::returnBook(Book* book) {
    for (int i = 0; i < borrowedBooks.size(); i++) {
        if (borrowedBooks[i] == book) {
            borrowedBooks.erase(borrowedBooks.begin() + i);
            book->setIsBorrowed(false);
            book->setIdBorrower(0);
            cout << "Book returned successfully" << endl;
            return;
        }
    }
    cout << "You have not borrowed this book" << endl;
}