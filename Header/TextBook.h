#pragma once

#include "StandardLibrary.h"
#include "Book.h"

class TextBook : public Book {
private:
    string subject;
public:
    TextBook();
    TextBook(string, string, int, string, bool);
    TextBook(string, string, int, string, bool, int);
    TextBook(const TextBook&);
    ~TextBook();

    string getType();
    string getSubject();
    void displayInfo();
    void setInformation();
};