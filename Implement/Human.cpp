#include "../Header/Human.h"

Human::Human() : fullname(""), day(0), month(0), year(0) {}
Human::Human(string fullname, int day, int month, int year) :
fullname(fullname), day(day), month(month), year(year) {}
Human::Human(const Human& human) :
fullname(human.fullname), day(human.day), month(human.month), year(human.year) {}
Human::~Human() {}

string Human::getFullname() {return fullname;}
string Human::getDateOfBirth() {
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}
int Human::getDay() {return day;}
int Human::getMonth() {return month;}
int Human::getYear() {return year;}