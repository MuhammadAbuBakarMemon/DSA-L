#include <iostream>
using namespace std;

int main(void)
{
    int *ptr = new int;
    *ptr = 100;

    cout << "Value stored in ptr (the dynamically allocated single block of memory) is: " << *(ptr) << endl;

    return 0;
}