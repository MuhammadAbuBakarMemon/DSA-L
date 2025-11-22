#include <iostream>
using namespace std;

void display(int ray[], int size)
{
    for (int m = 0; m < size; m++)
    {
        cout << *(ray+m) << " ";
    }
}

void decBSort(int ray[], int size)
{
    for (int m = 0; m < size - 1; m++)
    {
        for (int n = 0; n < size - 1 - m; n++)
        {
            if (ray[n] < ray[n+1])
            {
                swap(ray[n], ray[n+1]);
            }
        }
    }
}

void decEffBSort(int ray[], int size)
{

    int counter = 0;
    bool swaps = true;

    while (counter < size - 1 && swaps == true)
    {
    
        swaps = false;

        for (int m = 0; m < size - 1 - counter; m++)
        {
            if (ray[m] < ray[m + 1])
            {
                swap(ray[m], ray[m + 1]);
                swaps = true;
            }
        }

        counter++;
    }
    
}

int main(void)
{
    
    int ray[] {5, 1, 4, 3, 2};
    decBSort(ray, 5);
    display(ray, 5);

    cout << endl;

    decEffBSort(ray, 5);
    display(ray, 5);

    return 0;
}