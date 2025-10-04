#include <iostream>
using namespace std;

void display(int ray[], int size)
{
    for (int m = 0; m < size; m++)
    {
        cout << *(ray+m) << " ";
    }
}

void decISort(int ray[], int size)
{

    for (int m = 1; m < size; m++)
    {
        int data = ray[m];
        int prev = m - 1;

        while (prev >= 0 && ray[prev] < data)
        {
            ray[prev + 1] = ray[prev];
            prev--;
        }

        ray[prev + 1] = data;
    }

}

int main(void)
{
    
    int ray[] {5, 1, 4, 3, 2};
    decISort(ray, 5);
    display(ray, 5);

    cout << endl;

    return 0;
}