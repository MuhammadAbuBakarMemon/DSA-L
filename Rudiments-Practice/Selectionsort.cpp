#include <iostream>
using namespace std;

// Time Complexity O(n^2)

void selectionSort(int ray[], int s)
{
    for (int m = 0; m < s - 1; m++)
    {
        int sIdx = m;

        for (int n = m + 1; n < s; n++)
        {
            if (ray[sIdx] > ray[n])
            {
                sIdx = n;
            }
        }

        swap(ray[sIdx], ray[m]);
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