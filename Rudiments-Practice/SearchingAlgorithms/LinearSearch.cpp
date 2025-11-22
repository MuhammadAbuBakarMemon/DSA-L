#include <iostream>
using namespace std;

// Imrpoved version of Insertion sort

void lSearch(int ray[], int size, int key)
{
    for (int m = 0; m < size; m++)
    {
        if (key == ray[m])
        {
            cout << "Value [" << key << "] found at [" << m << "] index position, element number [" << m + 1 << "]////" << endl;
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
    printRay(ray, 5);
    cout << endl;
    lSearch(ray, 5, 3);

    return 0;
}