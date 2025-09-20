#include <iostream>
using namespace std;

void combSort(int arr[], int n) 
{
    int gap = n;
    bool swapped = true;

    while(gap != 1 || swapped) 
    {
        gap = (gap * 10) / 13;
        if(gap < 1) 
        {
            gap = 1;
        }

        swapped = false;

        for(int x = 0; x + gap < n; x++) 
        {
            if(arr[x] > arr[x + gap]) 
            {
                int temp = arr[x];
                arr[x] = arr[x + gap];
                arr[x + gap] = temp;
                swapped = true;
            }
        }
    }
}

int main() 
{
    int n;
    cout << "How many flight tickets? ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter ticket prices:\n";
    for(int x = 0; x < n; x++) 
    {
        cin >> arr[x];
    }

    combSort(arr, n);

    cout << endl << "Ticket prices sorted from lowest to highest:\n";
    for(int y = 0; y < n; y++) 
    {
        cout << arr[y] << " ";
    }
    cout << endl;

    cout << "\nCheapest 3 flight:\n";
    for(int z = 0; z < 3 && z < n; z++) 
    {
        cout << arr[z] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
