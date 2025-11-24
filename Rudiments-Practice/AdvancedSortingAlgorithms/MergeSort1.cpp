#include <iostream>
using namespace std;

void merge(int ray[], int st, int end, int mid)
{

    int i = st;
    int j = mid + 1;

    int* temp = new int [end - st + 1];
    int temp_it = 0;

    while  (i <= mid && j <= end)
    {
        if (ray[i] < ray[j])
        {
            temp[temp_it++] = ray[i++];
        }
        else 
        {
            temp[temp_it++] = ray[j++];
        }
    }

    while (i <= mid)
    {
        temp[temp_it++] = ray[i++];
    }

    while (j <= end)
    {
        temp[temp_it++] = ray[j++];
    }

    for (int m = 0; m < temp_it; m++)
    {
        ray[st + m] = temp[m];
    }

    delete[] temp;

}

void MergeSort(int ray[], int st, int end)
{

    if (st < end)
    {
        int mid = st + (end - st) / 2;

        MergeSort(ray,st, mid);
        MergeSort(ray, mid + 1, end);

        merge(ray, st, end, mid);
    }

}

void printRay(int ray[], int size)
{
    for (int m = 0; m < size; m++)
    {
        cout << ray[m] << " ";
    }

    cout << endl;
}

int main(void)
{
    
    int ray[] = {5, 2, 9, 1, 6, 3, 30, 23};
    int n = sizeof(ray) / sizeof(ray[0]);

    cout << "Before Sorting: " << endl;
    printRay(ray, n);

    cout << "\n";

    MergeSort(ray, 0, n - 1);

    cout << "After Sorting: " << endl;
    printRay(ray, n);

    return 0;
}