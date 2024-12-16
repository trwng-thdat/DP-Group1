#include "Header/StandardLibrary.h"
#include "Header/Factory.h"
#include "Header/Book.h"
#include "Header/Novel.h"
#include "Header/TextBook.h"
#include "Header/Strategy.h"
#include "Header/Facade.h"
#include "Header/Human.h"
#include "Header/Member.h"

void runProgram() {
    LibraryFacade library;
    int option = 0;
    while(option != 1) {
        cout << "\n=======================MENU=========================:\n" << endl;
        cout << "1. Exit" << endl;
        cout << "2. Search" << endl;
        cout << "3. Display all books" << endl;
        cout << "4. Add book" << endl;
        cout << "5. Add member" << endl;
        cout << "6. Display all members" << endl;
        cout << "7. Borrow book" << endl;
        cout << "8. Return book" << endl;
        cout << "Choose an option: ";
        cin >> option;
        cout << "========================\n";
        if (option == 2) 
            library.search();
        else if (option == 3) 
            library.displayAllBooks();
        else if (option == 4)
            library.addBook();
        else if (option == 5)
            library.addMember();
        else if (option == 6)
            library.displayAllMembers();
        else if (option == 7) {
            if (library.borrowBook())
                cout << "Borrowed successfully" << endl;
            else
                cout << "Borrowed failed" << endl;
        }
        else if (option == 8)
            library.returnBook();
        else if (option == 1)
            cout << "End!" << endl;
        else
            cout << "Invalid option" << endl;
    }
}

int main() {
    runProgram();
    return 0;
}