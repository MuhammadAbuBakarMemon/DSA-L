#include <iostream>
using namespace std;

// Time Complexity O(n^2)

void selectionSort(int ray[], int n)
{
    for (int m = 0; m < n - 1; m++)
    {
        int sIdx = m;

        for(int x = m + 1; x < n; x++)
        {
            if (ray[x] < ray[sIdx])
            {
                sIdx = x;
            }
        }

        swap(ray[m], ray[sIdx]);
    }
}

void printRay(int ray[], int size)
{
    for (int m = 0; m < size; m++)
    {
        cout << ray[m] << " ";
    }
}

int main(void)
{
    
    int ray[5] {4,1,5,2,3};
    selectionSort(ray, 5);
    printRay(ray, 5);

    return 0;
}