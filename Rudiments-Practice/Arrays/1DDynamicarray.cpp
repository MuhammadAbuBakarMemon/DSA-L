#include <iostream>
using namespace std;

int main(void)
{
    int size = 0;

    cout << "Enter size for your array: " << endl;
    cin >> size;

    int * ray = new int[size];
    
    cout << "Enter elemenets: " << endl;

    for (int m = 0; m < size; m++)
    {
        cout << "Array [" << m + 1 << "] - " << endl;
        cin >> ray[m];
    }

    for (int m = 0; m < size; m++)
    {
        cout << "Array ["  << m + 1 << "] - " << ray[m] << endl;
    }

    delete[] ray;

    return 0;
}