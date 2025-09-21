#include <iostream>
using namespace std;

// Time Complexity of O(n^2)

void bsort(int ray[], int s)
{
    for (int m = 0; m < s - 1; m++)
    {
        for (int n = 0; n < s - m - 1; n++)
        {
            if (ray[n] > ray[n+1])
            {
                swap(ray[n], ray[n+1]);
            }
        }
    }
}

void printRay(int ray[], int a)
{
    for(int m = 0; m < a; m++)
    {
        cout << ray[m] << " ";
    }

    cout << endl;
}

int main(void)
{
    // both methods for array declarations and initializations are valid 
    
    // int ray[5] {5, 2, 1, 4, 3};
    int ray[5] = {5, 2, 3, 1, 4};
    bsort(ray, 5);

    printRay(ray, 5);
    return 0;
}