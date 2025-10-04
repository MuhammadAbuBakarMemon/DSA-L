#include <iostream>
using namespace std;

void cSort(int ray[], int size)
{

    float shrink = 1.30;
    int gap =  size;

    bool swaps = true;

    while (gap > 1 || swaps == true)
    {
        gap = (int) (gap / (shrink));

        if (gap < 1) gap = 1;
        swaps = false;

        for (int m = 0; m + gap < size; m++)
        {
            if (ray[m] > ray[m + gap])
            {
                swap(ray[m], ray[m + gap]);
                swaps = true;
            }
        }
    }

}

void decCSort(int ray[], int size)
{

    const double shrink = 1.30;
    int gap = size;
    bool swaps = true;

    while (gap > 1 || swaps == true)
    {
        gap = (int) gap / shrink;

        if (gap < 1)
        {
            gap = 1;
        }

        swaps = false;

        for (int m = 0; m + gap < size; m++)
        {
            if (ray[m] < ray[m + gap])
            {
                swap(ray[m], ray[m + gap]);
                swaps = true;
            }
        }
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
    cSort(ray, 5);
    printRay(ray, 5);

    cout << endl;

    decCSort(ray, 5);
    printRay(ray, 5);

    return 0;
}