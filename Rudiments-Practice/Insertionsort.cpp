#include <iostream>
using namespace std;

// Time Complexity O(n^2)
void insertionSort(int ray[], int size)
{
    for (int m = 1; m < size; m++)
    {
        int temp = ray[m];
        int prev = m - 1;

        while (prev >= 0 && ray[prev] > temp)
        {
            ray[prev + 1] = ray[prev];
            prev--;
        }

        ray[prev + 1] = temp;
    }
}

void printRay(int ray[], int s)
{
    for (int m = 0; m < s; m++)
    {
        cout << ray[m] << " ";
    }
}

int main(void)
{
    
    int ray[5] {4, 1, 5, 2, 3};
    insertionSort(ray, 5);
    printRay(ray, 5);

    return 0;
}