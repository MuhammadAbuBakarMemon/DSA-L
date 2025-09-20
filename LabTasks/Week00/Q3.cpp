// Q3. Create a C++ classInventory that stores a list of item prices using DMA. The size of the
// inventory will be provided during object creation. Implement a deep copy constructor so that if
// one inventory object is copied to another, changes in one will not affect the other. In your
// program, create one inventory with some prices, copy it to another inventory, update a price in
// the copied version, and display both to verify they are separate.

#include <iostream>
#include <iomanip>
using namespace std;

class Inventory
{

    double * listofpri;
    int size;
    // need to keep track of the size of our dynamically allocated array via this additional variable
    // sizeof(array) - gives size of the array only
    // sizeof(pointer) - 4 bytes in 32 bit system, 8 bytes for a 64  bit system, only gives size of pointer
    // we need an extra variable to store the size whenever we are allocating the size of our array dynamically
    
    public:

        Inventory(int a) : size(a)
        {
            listofpri = new double[size];

            for (int m = 0; m < size; m++)
            {
                listofpri[m] = 0.00; 
            }
        }

        // Inventory(const Inventory& a)
        // {
            
        //     // Error: sizeof() if used on a pointer only returns a fixed size;
        //     // only use it on arrays
        //     // listofpri = new double[sizeof(a.listofpri) + 1];

        //     this->size = a.size;
        //     this->listofpri = new double[a.size];

        //     for (int m = 0; m < a.size; m++)
        //     {
        //         this->listofpri[m] = a.listofpri[m];
        //     }
        // }

        Inventory& operator= (const Inventory& obj)
        {
            if (this != &obj)
            {
                size = obj.size;

                delete[] this->listofpri;

                listofpri = new double[size];
                for (int m = 0; m < size; m++)
                {
                    listofpri[m] = obj.listofpri[m];
                }
            }

            return *this;
        }

        void setInventoryDetails(double m, int n)
        {
            this->listofpri[n] = m;
        }

        // I need to learn how to make perfect copy assignment operators....
        // Inventory& operator= (const Inventory& m)
        // {
        //     delete[] this->listofpri;
        //     this->listofpri = new double[m.size];

        //     for (int x = 0; x < m.size; x++)
        //     {
        //         this->listofpri[x] = m.listofpri[x];
        //     }
        // }

        void printList(void) const
        {
            for (int m = 0; m < size; m++)
            {
                cout << fixed << setprecision(2) << listofpri[m] << " ";
            }
            cout << endl;
        }

        ~Inventory()
        {
            delete[] listofpri;
        }

};

int main(void)
{
    
    Inventory i1(5);
    i1.setInventoryDetails(100.00, 0);
    i1.setInventoryDetails(200.00, 1);
    i1.setInventoryDetails(300.00, 2);
    i1.setInventoryDetails(400.00, 3);
    i1.setInventoryDetails(500.00, 4);
    Inventory i2(i1);

    cout << "Initial list...." << endl;
    i1.printList();
    i2.printList();

    i2.setInventoryDetails(450.00, 4);

    cout << "Manipulated lists...." << endl;
    i2.printList();

    return 0;
}