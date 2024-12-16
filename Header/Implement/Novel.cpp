#include "../Header/Novel.h"

Novel::Novel() : Book(), genre("") {}
Novel::Novel(string title, string author, int year, string genre, bool Borrowed) :
Book(title, author, year, Borrowed), genre(genre) {}
Novel::Novel(string title, string author, int year, string genre, bool Borrowed, int idBorrower) :
Book(title, author, year, Borrowed, idBorrower), genre(genre) {}
Novel::Novel(const Novel& novel) :
Book(novel.title, novel.author, novel.year, novel.isBorrowed), genre(novel.genre) {}
Novel::~Novel() {}

string Novel::getType() { return "novel"; }
void Novel::displayInfo() {
    cout << "Novel: " << title << " by " << author 
    << " (" << year << ") - " << genre << ", ";
    if (isBorrowed) cout << "Borrowed" << endl;
    else cout << "Available" << endl;
}

void Novel::setInformation() {
    Book::setInformation();
    cout << "Enter genre: ";
    getline(cin, genre);
}