#include <iostream>
#include <algorithm>
using namespace std;

// count sort used in radix sort

void countSort(int ray[], int size)
{

    int k = ray[0];
    for(int m = 1; m < size; m++)
    {
        k = max(ray[m], k);
    }

    int cray[k + 1] = {0};

    for (int m = 0; m < size; m++)
    {
        cray[ray[m]]++;
    }

    // error
    // for(int m = 1; m < size; m++)
    for(int m = 0; m <= size; m++)
    {
        cray[m] += cray[m - 1];
    }

    int temp[size] = {0};

    for(int m = size - 1; m >= 0; m--)
    {
        temp[--cray[ray[m]]] = ray[m];
    }

    for(int m = 0; m < size; m++)
    {
        ray[m] = temp[m];
    }

    cout << "Sorted Array: " << endl;
    for(int m = 0; m < size; m++)
    {
        cout << ray[m] << " ";
    }
    cout << endl;

}

int main(void)
{
    int ra[6] = {2, 4, 6, 4, 4, 2};
    
    countSort(ra, 6);

    return 0;
}