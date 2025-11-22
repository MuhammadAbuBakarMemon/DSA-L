#include <iostream>
using namespace std;

void efficientBSort(int ray[], int s)
{
    for (int m =  0; m < s - 1; m++)
    {
        bool swaps = false;

        for (int n = 0; n < s - m - 1; n++)
        {
            if (ray[n] > ray[n + 1])
            {
                swap(ray[n], ray[n + 1]);
                swaps = true;
            }
        }

        // checking for if array is already sorted....
        if (!swaps)
        {
            return;
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

    int ray[5]{4, 1, 5, 2, 3};
    efficientBSort(ray, sizeof(ray) / sizeof(int));
    printRay(ray, sizeof(ray) / sizeof(int));
    
    return 0;
}