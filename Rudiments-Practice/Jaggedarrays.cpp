#include <iostream>
using namespace std;

int main(void)
{
    
    int r = 3;

    int **ray = new int*[r];

    int size[r];
    for (int m = 0; m < r; m++)
    {
        cout << "Enter sizes for your jagged array's Row[" << m + 1 << "]: " << endl;
        cin >> size[m];
    }


    for (int m = 0; m < r; m++)
    {
        ray[m] = new int[size[m]];
    }

    cout << "Start entering values for your jagged array...." << endl;

    for (int m = 0; m < r; m++)
    {
        for (int n = 0; n < size[m]; n++)
        {
            cout << "Ray [" << m << "][" << n << "] - " << endl;
            // cin >> ray[m][n];
            cin >> *( *(ray + m) + n);
        }
    }

    cout << "Outputting values for your jagged array: " << endl;
    for (int m = 0; m < r; m++)
    {
        for (int n = 0; n < size[m]; n++)
        {
            cout << ray[m][n] << " ";
        }

        cout << "\n";
    }

    // deallocationg the dynamically allocated jagged array
    for (int m = 0; m < r; m++)
    {
        delete[] ray[m];
    }
    delete[] ray;

    return 0;
}