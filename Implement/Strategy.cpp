#include "../Header/Strategy.h"

vector<Book*> searchByTitle::searchBook(vector<Book*>& books, string title) {
    vector<Book*> result;
    for (Book* book : books) {
        if (book->getTitle() == title) 
            result.push_back(book);
    }
    return result;
}

vector<Book*> searchByAuthor::searchBook(vector<Book*>& books, string author) {
    vector<Book*> result;
    for (Book* book : books) {
        if (book->getAuthor() == author) 
            result.push_back(book);
    }
    return result;
}

vector<Book*> searchByType::searchBook(vector<Book*>& books, string type) {
    vector<Book*> result;
    for (Book* book : books) {
        if (book->getType() == type) 
            result.push_back(book);
    }
    return result;
}