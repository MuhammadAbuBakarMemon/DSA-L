// Q2. Create a MovieTicket class to manage bookings. The class should store the movie name (use
// DMA) and the seat number. Implement the Rule of Three by writing a destructor, a copy
// constructor, and a copy assignment operator to ensure deep copying of data. In your program,
// create one ticket, make a copy of it, and also assign it to another ticket object. Then change the
// movie name in one of the copies and confirm that the original booking remains unaffected.

#include <iostream>
#include <cstring> // we get the strcpy function from here
using namespace std;

class MovieTicket
{

    char * mvnam;
    char * sno;

    public:
        MovieTicket()
        {
            mvnam = new char[50];
            // mvnam = new char[50] {"Moana"}; Error
            strcpy(mvnam, "Moana");
            this->sno = new char[10];
            // sno = new char[10] {"MV9001"}; Error
            strcpy(sno, "MV9001");
        }

        // Incorrect, breaks rule of three's implementation 
        // classical example of a Broken Copy Constructor
        /*
            Allocating memory with new and then we immediately lost the newly allocated memory by overwriting the pointer
            both objects now share the same pointer, hence shallow copy 
            which leads to double deletion, data corruption and reseource sharing
        */

        // MovieTicket(const MovieTicket& m)
        // {
        //     this->mvnam = new char [50];
        //     this->mvnam = m.mvnam
        //     this->sno = new char [10];
        //     this->sno = m.sno;
        // }

        MovieTicket(const MovieTicket& m)
        {
            this->mvnam = new char[strlen(m.mvnam) + 1];
            strcpy(this->mvnam, m.mvnam);

            this->sno = new char[strlen(m.sno) + 1];
            strcpy(this->sno, m.sno);
        }

        // Another classical example of a broken copy assignment operator

        // MovieTicket operator = (const MovieTicket& m)
        // {
        //     this->mvnam = m.mvnam;
        //     this->sno = m.sno;
        // }

        MovieTicket& operator = (const MovieTicket& m)
        {
            if (this != &m)
            {
                delete[] this->mvnam;
                delete[] this->sno;

                this->mvnam = new char[strlen(m.mvnam) + 1];
                strcpy(mvnam, m.mvnam);

                this->sno = new char[strlen(m.sno)];
                strcpy(this->sno, m.sno);
            }

            return *this;
        }

        void setMovieName(const char* m)
        {
            delete[] this->mvnam;

            this->mvnam = new char[strlen(m) + 1];
            strcpy(mvnam, m);
        }

        void printTicket(void)
        {
            cout << "Movie Name: " << mvnam << endl;
            cout << "Seat Number: " << sno << endl;
        }

        ~MovieTicket()
        {
            delete[] mvnam;
            delete[] sno;
            cout << "Destructor for Movie Ticket was called...." << endl;
        }
};

int main(void)
{
    MovieTicket m1;
    MovieTicket m2(m1);
    MovieTicket m3;
    m3 = m1;

    m1.printTicket();
    cout << endl;

    m2.printTicket();
    cout << endl;

    m3.printTicket();
    cout << endl;

    cout << "Manipulating the object m2...." << endl;

    m2.setMovieName("Undeikha Wajood");

    m1.printTicket();
    cout << endl;

    m2.printTicket();
    cout << endl;

    m3.printTicket();
    cout << endl;

    return 0;
}