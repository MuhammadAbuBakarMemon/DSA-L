#include <iostream>
using namespace std;

void merge(int ray[], int st, int end, int mid)
{

    int i = st;
    int j = mid + 1;

    int* temp = new int [end - st + 1];
    int t_it = 0;
    
    while (i <= mid && j <= end)
    {
        if (ray[i] < ray[j])
        {
            temp[t_it++] = ray[i++];
        }
        else
        {
            temp[t_it++] = ray[j++];
        }
    }

    while (i <= mid)
    {
        temp[t_it++] = ray[i++];
    }

    while (j <= end)
    {
        temp[t_it++] = ray[j++];
    }

    for(int k = 0; k < t_it; k++)
    {
        ray[st + k] = temp[t_it]; 
    }

}

void MergeSort(int ray[], int st, int end)
{

    if (et < end)
    {

        int mid = st + (end - st) / 2;

        MergeSort(ray, st, mid);
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
    
    return 0;
}