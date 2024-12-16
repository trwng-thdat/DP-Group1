#include "../Header/TextBook.h"

TextBook::TextBook() : Book(), subject("") {}
TextBook::TextBook(string title, string author, int year, string subject, bool borrowed) :
Book(title, author, year, borrowed), subject(subject) {}
TextBook::TextBook(string title, string author, int year, string subject, bool borrowed, int idBorrower) :
Book(title, author, year, borrowed, idBorrower), subject(subject) {}
TextBook::TextBook(const TextBook& textBook) :
Book(textBook.title, textBook.author, textBook.year, textBook.isBorrowed), subject(textBook.subject) {}
TextBook::~TextBook() {}

string TextBook::getType() { return "textbook"; }
string TextBook::getSubject() { return subject; }
void TextBook::displayInfo() {
    cout << "TextBook: " << title << " by " << author 
    << " (" << year << ") - " << subject << ", ";
    if (isBorrowed) cout << "Borrowed" << endl;
    else cout << "Available" << endl;
}

void TextBook::setInformation() {
    Book::setInformation();
    cout << "Enter subject: ";
    getline(cin, subject);
}