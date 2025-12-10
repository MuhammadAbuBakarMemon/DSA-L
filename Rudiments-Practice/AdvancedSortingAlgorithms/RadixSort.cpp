// the only non-comparsion sort that we have......
#include <iostream>
using namespace std;

int getMax(int ray[], int size)
{
    int max = ray[0];

    for (int m = 0; m < size; m++)
    {
        if(ray[m] > max)
        {
            max = ray[m];
        }
    }
    return max;
}

void countSort(int ray[], int size, int exp)
{
    int cray[10] = {0};

    for(int m = 0; m < size; m++)
    {
        cray[(ray[m] / exp) % 10]++;
    }

    for(int m = 1; m < 10; m++)
    {
        cray[m] += cray[m -1];
    }

    int temp[size] = {0};

    for(int m = size - 1; m >= 0; m--)
    {
        temp[--cray[(ray[m]/exp) % 10]] = ray[m];
    }

    for(int m = 0; m < size; m++)
    {
        ray[m] = temp[m];
    }

}

void radixSort(int ray[], int size)
{
    int max = getMax(ray, size);
    
    for(int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(ray, size, exp);
    }

}

int main(void)
{

    int ray[] = {221, 453, 64, 125, 8, 948, 33, 121};
    int size = sizeof(ray)/sizeof(ray[0]);

    radixSort(ray, size);

    cout << "Sorted version: " << endl;
    for (int m = 0; m < size; m++)
    {
        cout << ray[m] << " ";
    } 
    cout << endl;
    
    return 0;
}