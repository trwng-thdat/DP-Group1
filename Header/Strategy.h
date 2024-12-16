#pragma once

#include "StandardLibrary.h"
#include "Book.h"

class searchStrategy {
public:
    virtual ~searchStrategy() {}
    virtual vector<Book*> searchBook(vector<Book*>&, string) = 0;
};

class searchByTitle : public searchStrategy {
public:
    vector<Book*> searchBook(vector<Book*>&, string);
};

class searchByAuthor : public searchStrategy {
public:
    vector<Book*> searchBook(vector<Book*>&, string);
};

class searchByType : public searchStrategy {
public:
    vector<Book*> searchBook(vector<Book*>&, string);
};