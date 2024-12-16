#pragma once

#include "StandardLibrary.h"
#include "Book.h"

class Novel : public Book {
private:
    string genre;
public:
    Novel();
    Novel(string, string, int, string, bool);
    Novel(string, string, int, string, bool, int);
    Novel(const Novel&);
    ~Novel();

    string getType();
    string getGenre();
    void displayInfo();
    void setInformation();
};