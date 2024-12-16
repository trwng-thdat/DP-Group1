#pragma once
#include "StandardLibrary.h"
#include "Human.h"
#include "Book.h"

class Member : public Human {
private:
    int ID;
    static int staticID;
    vector<Book*> borrowedBooks;
public:
    Member();
    Member(string, int, int, int);
    Member(string, int, int, int, int);
    Member(const Member&);
    ~Member();

    static void setStaticID(int);
    static int getStaticID();
    int getID();
    void displayInfo();
    void borrowBook(Book*);
    void returnBook(Book*);
};