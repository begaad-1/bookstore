#include <vector>
#include <string> 
#include <iostream>
using namespace std;
class Book {
public:
    Book( string title,  string author, string borrower, bool borrowed);
    string getTitle() ;
    bool getstate() ;
    string getAuthor() ;
    string getborrower() ;

 
  

    string title;
    string author;
    bool borrowed;
    string borrower;
};

class Library {
public:
    vector<Book> books;
    void addBook( string title,  string author);
    void removeBookByTitle( std::string title);
    void displayBooks() ;
    void addBook( Book& book) { books.push_back(book); }
    void borrowBook( string name,  string borrower) {
      
        bool bookFound = false;
        for (auto& book : books) {
            if (book.getTitle() == name) {
                if (book.borrowed) {
                    book.borrower = borrower;
                    book.borrowed = false;
                    bookFound = true;
                }
                else {
                    cout << "this book is already taken\n" << endl;
                    bookFound = true;
                }
                break;
            }
        }
        if (!bookFound) {
            cout << "this book is not available" << endl;
        }
    }

     Book* findBookByName( string& name)  {
        for ( auto& book : books) {
            if (book.getTitle() == name) {
                return &book;
            }
        }
        return nullptr;
    }

     Book* findBookByAuthor( string& author)  {
        for ( auto& book : books) {
            if (book.getAuthor() == author) {
                return &book;
            }
        }
        return nullptr;
    }
    void namesearch(string bookname) {

         Book* foundBook = findBookByName(bookname);
        if (foundBook) {
            cout << "Found book: " << foundBook->getTitle() << " by " << foundBook->getAuthor() << endl;
            string borrower = foundBook->getborrower();
                if (borrower != "none") {
                    cout << "the borrower is: " << borrower<<endl;
            }
        }
        else {
            cout << "Book not found." << endl;
        }
    }
    void AuthorSearch(string author) {
         Book* foundBook = findBookByAuthor(author);
        if (foundBook) {
            cout << "Found book: " << foundBook->getTitle() << " by " << foundBook->getAuthor() << endl;
            string borrower = foundBook->getborrower();
            if (borrower != "none") {
                cout << "the borrower is: " << borrower << endl;
            }
        }

        else {
            cout << "Book not found." << endl;
        }
    }
 
};