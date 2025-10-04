#include <iostream>
using namespace std;

// Imrpoved version of Insertion sort

void shellSort(int ray[], int size)
{

    const double shrink = 1.30;
    for (int gap = size; gap > 0; gap /= shrink)
    {

        for (int m = gap; m < size; m++)
        {
            int dabba = ray[m];
            int prev = m;
            
            while (prev >= gap && ray[prev - gap] > dabba)
            {
                ray[prev] = ray[prev - gap];
                prev -= gap; 
            }

            ray[prev] = dabba;
        }
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

    return 0;
}