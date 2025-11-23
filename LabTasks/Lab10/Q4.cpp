// 4. Given two binary max-heaps as arrays, merge them to form a new max-heap.

#include <iostream>
#include <algorithm>
using namespace std;

void sink(int ray[], int size, int m)
{
    int largest = m;
    int left = (2 * m) + 1;
    int right = (2 * m) + 2;

    if (left < size && ray[left]> ray[largest])
    {
        largest = left;
    }

    if (right < size && ray[right] > ray[largest])
    {
        largest = right;
    }

    if (largest != m)
    {
        swap(ray[largest], ray[m]);
        sink(ray, size, largest);
    }
}

void heapify(int ray[], int size)
{
    int stIdx = (size - 1) / 2;
    
    for (int m = stIdx; m >= 0 ; m--)
    {
        sink(ray, size, m);
    }
    
}

int* concatenate(int r1[], int m, int r2[], int n)
{
    // int o = m + n;

    int* ray = new int [m + n];

    for (int x = 0;  x < m; x++)
    {
        ray[x] = r1[x];
    }

    for (int y = m, x = 0; y < (m + n); y++, x++)
    {
        ray[y] = r2[x];
    }

    heapify(ray, m + n);

    return ray;

}

void printHeap(int ray[], int heapsize)
{
    for (int m = 0; m < heapsize; m++)
    {
        cout << ray[m] << " ";
    }

    cout << endl;
}

int main(void)
{

    int ray1[] = {1, 34, 23, 2, 4};
    int s1 = sizeof(ray1)/sizeof(ray1[0]);

    int ray2[] = {11, 0, 90, 30};
    int s2 = sizeof(ray2)/sizeof(ray2[0]);

    int* res = concatenate(ray1, s1, ray2, s2);

    printHeap(res, s1 + s2);

    delete[] res;

    return 0;
}