
#include "Library.h"
#include <iostream>
using namespace std;
// Implementazione della classe Book
Book::Book( string title,  string author, string borrower,  bool borrowed)
    : title(title), author(author) , borrowed(borrowed),borrower(borrower){}

string Book::getTitle()  {
    return title;
}

bool Book::getstate() 
{
    return borrowed;
}

string Book::getAuthor()  {
    return author;
}

string Book::getborrower() 
{
    return borrower;
}





// Implementazione della classe Library
void Library::addBook( string title,  string author) {
    
    books.emplace_back(title, author,"none", true);
}

void Library::removeBookByTitle( string title) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getTitle() == title) {
            books.erase(it);
            cout << "Book \"" << title << "\" removed from the library." << endl;
            return;
        }
    }
    cout << "Book \"" << title << "\" not found in the library." << endl;
}

void Library::displayBooks()  {
    if (books.empty()) {
        cout << "No books in the library." << endl;
    }
    else {
        for ( auto& book : books) {
            cout << "Title: " << book.getTitle() << "\nAuthor: " << book.getAuthor() << "\nstate: "; 
            bool state = book.getstate();
            if (state == true)
            {
                cout << "available" << endl;
            }
            else
                cout << "borrowed";
            cout << endl;
            string name = book.getborrower();
            if (name != "none") {
                cout << "the borrower: " << name<<endl;
            }
            cout << endl;
        }
    }
}