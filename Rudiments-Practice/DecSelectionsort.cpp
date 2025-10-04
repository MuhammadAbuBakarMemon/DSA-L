#include <iostream>
using namespace std;

void display(int ray[], int size)
{
    for (int m = 0; m < size; m++)
    {
        cout << *(ray+m) << " ";
    }
}

void decSSort(int ray[], int size)
{

    for (int m = 0; m < size - 1; m++)
    {
        int li = m;

        for (int n = m + 1; n < size; n++)
        {
            if (ray[li] < ray[n])
            {
                li = n;
            }
        }

        swap(ray[li], ray[m]);
    }

}

int main(void)
{
    
    int ray[] {5, 1, 4, 3, 2};
    decSSort(ray, 5);
    display(ray, 5);

    cout << endl;

    return 0;
}