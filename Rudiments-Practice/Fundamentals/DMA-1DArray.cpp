#include <iostream>
using namespace std;

int main(void)
{
    int * ray;
    int size;

    cout << "Enter the size of the array: " << endl;
    cin >> size;

    ray = new int [size];

    cout << "Enter elements for your array: " << endl;
    for (int m = 0; m < size; m++)
    {
        cout << "Array [" << m + 1 << "] - " << endl;
        cin >> *(ray+m);
    }

    cout << "\nPrinting elements of the array: " << endl;
    for (int m = 0; m < size; m++)
    {
        cout << "Array [" << m + 1 << "] - " << ray[m] << endl;
    }

    return 0;
}