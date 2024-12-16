#pragma once

#include "StandardLibrary.h"
#include "Book.h"
#include "Novel.h"
#include "TextBook.h"
#include "Human.h"
#include "Member.h"

class BookFactory {
public:
    virtual ~BookFactory() {}
    virtual Book* createBook() = 0;
    virtual Book* createBook(string) = 0;
};

class NovelFactory : public BookFactory {
public:
    Book* createBook();
    Book* createBook(string);
};

class TextBookFactory : public BookFactory {
public:
    Book* createBook();
    Book* createBook(string);
};

class HumanFactory {
public:
    virtual ~HumanFactory() {}
    virtual Human* createHuman(string) = 0;
};

class MemberFactory : public HumanFactory {
public:
    Human* createHuman(string);
};