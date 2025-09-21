#include <iostream>
using namespace std;

int main(void)
{
    int r = 0;
    int c = 0;

    cout << "Enter the columns and rows for your matrix: " << endl;
    cin >> r >> c;

    // int ** ray = new int*[r];
    // for (int m = 0; m < r; m++)
    // {
    //     ray[m] = new int[c];
    // }

    int **ray = new int* [r];
    for (int m = 0; m < r; m++)
    {
        ray[m] =  new int[c];
    }

    cout << "Enter elements for your 2D Array: " << endl;

    for (int m = 0; m < r; m++)
    {
        for (int n = 0; n < c; n++)
        {
            cout << "Array [" << m + 1 << "][" << n + 1 << "] - " << endl;
            cin >> ray[m][n];
        }
    }

    cout << "\n";

    cout << "Printing elements fo your 2D Array: " << endl;

    for (int m = 0; m < r; m++)
    {
        for (int n = 0; n < c; n++)
        {
            cout << ray[m][n] << " ";
        }

        cout << endl;
    }

    for (int m = 0; m < r; m++)
    {
        delete[] ray[m];
    }

    return 0;
}