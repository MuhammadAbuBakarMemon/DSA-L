#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) 
{
    for(int x = 1; x < n; x++) 
    {
        int key = arr[x];
        int y = x - 1;
        while(y >= 0 && arr[y] > key) 
        {
            arr[y+1] = arr[y];
            y--;
        }
        arr[y+1] = key;
    }
}

int binarySearch(int arr[], int n, int target) 
{
    int low = 0, high = n - 1;
    while(low <= high) 
    {
        int mid = (low + high) / 2;
        if(arr[mid] == target) 
        {
            return mid;
        } 
        else if(arr[mid] < target) 
        {
            low = mid + 1;
        } 
        else 
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main() 
{
    int n;
    cout << "Emter number of students students? ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter scores:\n";
    for(int x = 0; x < n; x++) 
    {
        cin >> arr[x];
    }

    insertionSort(arr, n);

    cout << endl << "Scores in ascending order:\n";
    for(int y = 0; y < n; y++) 
    {
        cout << arr[y] << " ";
    }
    cout << endl;

    int searchScore;
    cout << "\nEnter a score to search: ";
    cin >> searchScore;

    int z = binarySearch(arr, n, searchScore);

    if(z != -1) 
    {
        cout << "Score found. Student's Rank: " << z + 1 << endl;
    } 
    else 
    {
        cout << "Score not found" << endl;
    }

    delete[] arr;
    return 0;
}
