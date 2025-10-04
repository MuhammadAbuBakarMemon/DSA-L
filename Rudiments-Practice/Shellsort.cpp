#include <iostream>
using namespace std;

// Imrpoved version of Insertion sort

void shellSort(int ray[], int size)
{

    const double shrink = 1.30;
    int gap = (int) gap / shrink;

    if (gap < 1) gap = 1;

    for (int m = 1; m + gap < size; m++)
    {
        int key = ray[m];
        int prev = m - gap;

        while (prev >= 0 && ray[prev] > key)
        {
            ray[prev + gap] = ray[prev];
            prev -= gap;
        }

        ray[prev + gap] = key;
    }

};

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
    shellSort(ray, 5);
    printRay(ray, 5);

    cout << endl;

    // decCSort(ray, 5);
    // printRay(ray, 5);

    return 0;
}