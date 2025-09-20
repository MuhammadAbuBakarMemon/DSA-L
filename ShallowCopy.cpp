/*

Two ways to copy 
1) Copy Constructor 

Object Obj1(Obj);
or
Object Obj1 = Obj;

2) Copy Assignment Operaator 
Object Obj1;
Obj1 = Obj;

*/

// Shallow Copy Example 

class Box 
{

    public:
        int * size;

        Box(int s)
        {
            size = new int (s);
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
    
    Box box1(30);
    Box box2 = box1;

    cout << box1.size << endl;
    cout << box2.size << endl;
    
    return 0;
}