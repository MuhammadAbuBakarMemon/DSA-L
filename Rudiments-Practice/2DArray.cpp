#include <iostream>
using namespace std;

int main(void)
{
    
    int ray [2][3] = {{1, 2, 3}, {4, 5, 6}};

    cout << "2-D Array Example: " << endl;

    for (int m = 0; m < 2; m++)
    {
        for (int n = 0; n < 3; n++)
        {
            cout << ray[m][n] << " ";
        }

        cout << "\n";
    }
    return 0;
}