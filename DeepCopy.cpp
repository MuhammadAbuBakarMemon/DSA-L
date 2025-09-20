// Deep Copy 

class Box
{

    public: 
        int * size;

        Box (int s)
        {
            size = new int (s);
        }

        // Deep Copy Constructor 
        Box (const Box& b)
        {
            this->size = new int (*b.size);
        }

        ~Box()
        {
            delete size;
        }

};

#include <iostream>
using namespace std;

int main(void)
{
    
    Box o1(30);
    Box o2(o1);

    cout << o1.size << endl;
    cout << o2.size << endl;

    return 0;
}