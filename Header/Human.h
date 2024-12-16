#pragma once
#include "StandardLibrary.h"

class Human {
protected:
    string fullname;
    int day;
    int month;
    int year;
public:
    Human();
    Human(string, int, int, int);
    Human(const Human&);
    ~Human();

    string getFullname();
    string getDateOfBirth();
    int getDay();
    int getMonth();
    int getYear();

    virtual void displayInfo() {};
    virtual void borrowBook() {};
};