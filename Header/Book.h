#pragma once

#include "StandardLibrary.h"

class Book {
protected:
    string title;
    string author;
    int year;
    int idBorrower;
    bool isBorrowed;
public:
    Book();
    Book(string, string, int, bool);
    Book(string, string, int, bool, int);
    Book(const Book&);

    string getTitle();
    string getAuthor();
    int getYear();
    void setIsBorrowed(bool);
    void setIdBorrower(int);
    bool getIsBorrowed();
    int getIdBorrower();
    
    virtual ~Book();
    virtual void setInformation();
    virtual string getGenre() { return ""; }
    virtual string getSubject() { return ""; }
    virtual string getType() = 0;
    virtual void displayInfo() = 0;
};