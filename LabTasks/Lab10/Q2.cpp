// A data analytics company stores performance metrics in the form of a min-heap to easily
// access the smallest values. However, for generating reports that prioritize the highest metrics
// first, the system needs to reorganize the data into a max-heap structure. The task is to
// efficiently convert the given array representation of a min-heap into a max-heap, ensuring
// that the largest element becomes the root and the heap property is maintained throughout.

#include <iostream>
#include <algorithm>
using namespace std;

int gPI(int m)
{
    return ( (m - 1) / 2);
}

int gRCI(int m)
{
    return ( (2 * m) + 2);
}

int gLCI(int m)
{
    return ( (2 * m) + 1);
}

void sink(int ray[], int heapsize, int m)
{
    int lar = m;
    int left = gLCI(m);
    int right = gRCI(m);

    if (left < heapsize && ray[left] > ray[lar])
    {
        lar = left;
    }

    if (right < heapsize && ray[right] > ray[lar])
    {
        lar = right;
    }

    if (lar != m)
    {
        swap(ray[lar], ray[m]);
        sink(ray, heapsize, lar);
    }

}

void heapify(int ray[], int n)
{

    int stIdx = (n - 1) / 2;

    for (int m = stIdx; m >= 0; m--)
    {
        sink(ray, n, m);
    }

}

void printHeap(int ray[], int size)
{

    for (int m = 0; m < size; m++)
    {
        cout << ray[m] << " ";
    }

    cout << "\n";

}

int main(void)
{
    
    int ray[] = {1, 2, 3, 4, 5, 6, 7};
    int s = sizeof(ray)/sizeof(ray[0]);

    heapify(ray, s);

    printHeap(ray, s);

    return 0;
}