#include "../Header/Book.h"

Book::Book() : title(""), author(""), year(0), isBorrowed(false) {}
Book::Book(string title, string author, int year, bool Borrowed) : 
title(title), author(author), year(year), idBorrower(0) , isBorrowed(Borrowed) {}
Book::Book(string title, string author, int year, bool Borrowed, int idBorrower) :
title(title), author(author), year(year), idBorrower(idBorrower), isBorrowed(Borrowed) {}
Book::Book(const Book& book) :
title(book.title), author(book.author), year(book.year), isBorrowed(book.isBorrowed) {}
Book::~Book() {}

string Book::getTitle() {return title;}
string Book::getAuthor() {return author;}
int Book::getYear() {return year;}
void Book::setIsBorrowed(bool Borrowed) {isBorrowed = Borrowed;}
void Book::setIdBorrower(int id) {idBorrower = id;}
bool Book::getIsBorrowed() {return isBorrowed;}
int Book::getIdBorrower() {return idBorrower;}

void Book::setInformation() {
    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter Year of publication: ";
    cin >> year;
    cin.ignore();
}