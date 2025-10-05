// 4. A local bookstore wants to organize its books by price in ascending order. Write a program that accepts
// the prices of n books and sorts them using Bubble Sort.
#include <iostream>
#include <iomanip>
using namespace std;

void bSort(float ray[], int size)
{
    for (int m = 0; m < size - 1; m++)
    {
        for (int n = 0; n < size - 1 - m; n++)
        {
            if (ray[n] > ray[n + 1])
            {
                swap(ray[n], ray[n + 1]);
            }
        }
    }
}

void effBSort(float ray[], int size)
{
    int counter = 0;
    bool swaps = true;

    while (counter < size && swaps == true)
    {
        swaps = false;

        for (int m = 0; m < size - 1; m++)
        {
            if (ray[m] > ray[m + 1])
            {
                swap(ray[m], ray[m + 1]);
                swaps = true;
            }
        }
        counter++;
    }
}

void display(float ray[], int size)
{
    for (int m = 0; m < size; m++)
    {
        cout << fixed << setprecision(2) << ray[m] << " ";
    }
    cout << "\n";
}

int main(void)
{
    
    int size = 0;

    cout << "Please enter the number for the prices of books that you would like to store: " << endl;
    cin >> size;

    float *ray = new float [size];
    cout << "Please enter the prices of your books into the data structure: " << endl;

    for (int m = 0; m < size; m++)
    {
        cout << "Book No#0" << m + 1 << " price: \n";
        cin >> ray[m];
    }

    display(ray, size);

    effBSort(ray, size);
    display(ray, size);

    return 0;
}