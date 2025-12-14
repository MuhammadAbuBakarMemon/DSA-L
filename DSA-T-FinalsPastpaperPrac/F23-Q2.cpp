#include <iostream>
using namespace std;

int mergeCount(int ray[], int temp[], int st, int en, int mid)
{
    int i = st;
    int j = mid + 1;
    int it = 0;
    int invcount = 0;

    while (i <= mid && j <= en)
    {
        if (ray[i] <= ray[j])
        {
            temp[it++] = ray[i++];
        }
        else
        {
            temp[it++] = ray[j++];
            invcount += (mid - i + 1);
        }
    }

    while (i <= mid)
    {
        temp[it++] = ray[i++];
    }

    while (j <= en)
    {
        temp[it++] = ray[j++];
    }

    for (int m = 0; m < it; m++)
    {
        ray[st + m] = temp[m];
    }

    return invcount;
}

int mergeSort(int ray[], int temp[], int st, int en)
{
    int invcount = 0;

    if (st < en)
    {

        int mid = st + (en - st)/2;

        invcount += mergeSort(ray, temp, st, mid);
        invcount += mergeSort(ray, temp, mid + 1, en);

        invcount += mergeCount(ray, temp, st, en, mid);
    }

    return invcount;
}

int main(void)
{

    int N;
    
    cout << "Enter the number of distinct elements in the array: " << endl;
    cin >> N;
    
    int* ray = new int [N];
    int* res = new int [N];

    cout << "Enter " << N << " distinct integers: " << endl;
    for (int m = 0; m < N; m++)
    {
        cout << "Integer No#" << m + 1 << ": ";
        cin >> ray[m];
    }

    int r = 0;

    r = mergeSort(ray, res, 0, N - 1);

    cout << "Number of Inversions are: " << r << endl;
    return 0;
}