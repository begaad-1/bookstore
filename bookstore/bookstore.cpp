#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Library.h"
using namespace std;
Library library;
string bookName, bookAuthor;



int main() {

    int choice;
    string title, author;
    string nameOfAuthor;
    string nameOfBook;
    string borrower;
    do {
        cout << endl<<endl;
        cout << "Library Management System\n";
        cout << "----------------------------------------X-----------------------------------------\n" << endl;
        cout << "press the following numbers to do whatever you want\n" << endl;
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Display Books\n";
        cout << "4. search for a book by title\n";
        cout << "5. search for a book by author\n";
        cout << "6. borrow a book by name\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl << endl;
        switch (choice) {

        case 1:
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            library.addBook(title, author);
            cout << "you had added the book successfully" << endl;
            cout << endl << endl;
            break;
        case 2:
            cout << "Enter title of the book to remove: ";
            cin.ignore();
            getline(cin, title);
            library.removeBookByTitle(title);
            cout << "you had deleted the book successfully" << endl;
            cout << endl << endl;
            break;
        case 3:
            library.displayBooks();
            cout << endl << endl;
            break;
        case 4:
           
            cout << "enter the title of the book\n";
            cin.ignore();
            getline(cin, nameOfBook);
            library.namesearch(nameOfBook);
            cout << endl << endl;
            break;
        case 5:
         
            cout << "enter the author of the book\n";
            cin.ignore();
            getline(cin, nameOfAuthor);
            library.AuthorSearch(nameOfAuthor);
            cout << endl << endl;
            break;
        case 6:
            cout << "enter the title of the book you want to borrow\n";
            cin.ignore();
            getline(cin, nameOfBook);
            cout << "enter your name" << endl;
            getline(cin, borrower);
            library.borrowBook(nameOfBook,borrower);
            cout << endl << endl;
            break;
        case 7:
            cout << "Exiting...\n";
            cout << endl << endl;
            break;
        default:
            cout << "Invalid choice, please try again.\n";
            cout << endl << endl;
            break;
        }
    } while (choice != 7);

   

    return 0;
}