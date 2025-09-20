// Q1. Suppose you’re making a library system. Create a Book class that stores the book’s title, author,
// and price. The library system should be able to create a book with default values when details are
// unknown, create a book with given details when new books are purchased, and make a copy of an
// existing book record for testing purposes. In your program, create three book objects to show the
// use of three different constructors:
// 1. Object one using the default constructor to create an object with default values.
// 2. Object two with given values input by the user.
// 3. Object three created using the copy constructor from the second book.
// Display all book details to verify correct initialization and copying.

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Book 
{

    string bktit;
    string bkauth;
    double pri;

    public:
        Book() : bktit("AbuBakar's Biography"), bkauth("Abu Bakar"), pri(99999) {}

        Book(const string& m, const string& n, double o)
        {
            bktit = m;
            bkauth = n;
            pri = o;
        }

        Book(const Book& b)
        {
            this->bktit = b.bktit;
            this->bkauth = b.bkauth;
            this->pri = b.pri;
        }

        void printDetails(void)
        {
            cout << "Book's Title: " << bktit << endl;
            cout << "Book's Author: " << bkauth << "\n";
            cout << "Book's Price: " << std::fixed << std::setprecision(2) << pri << std::endl;
        }

        ~Book()
        {
            cout << "Destructor for book was called...." << endl;
        }

};

int main(void)
{
    
    Book b1;
    b1.printDetails();
    cout << endl;

    Book b2("A Lost Soul", "Muhammad Ali", 175000.00);
    b2.printDetails();
    cout << endl;

    Book b3(b2);
    b3.printDetails();
    cout << endl;

    return 0;
}