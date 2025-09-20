#include <iostream>
using namespace std;

void selectionSort(int ray[], int n) 
{
    for(int x = 0; x < n - 1; x++) 
    {
        int maxIdx = x;
        for(int y = x + 1; y < n; y++) 
        {
            if(ray[y] > ray[maxIdx]) 
            {
                maxIdx = y;
            }
        }
        int temp = ray[x];
        ray[x] = ray[maxIdx];
        ray[maxIdx] = temp;
    }
}

void linearSearch(int ray[], int n, int target) 
{
    int first = -1, last = -1;
    for(int z = 0; z < n; z++) 
    {
        if(ray[z] == target) 
        {
            if(first == -1) 
            {
                first = z;
            }
            last = z;
        }
    }

    if(first != -1) 
    {
        cout << "\nYes, that salary exists in the records." << endl;
        cout << "The first employee with this salary is at position " << first + 1 << "." << endl;
        cout << "The last employee with this salary is at position " << last + 1 << "." << endl;
    } 
    else 
    {
        cout << "\nSorry, no employee earns that salary." << endl;
    }
}

int main() 
{
    int n;
    cout << "How many employee salaries would you like to enter? ";
    cin >> n;

    int *ray = new int[n];

    cout << "\nPlease enter the salaries one by one:\n";
    for(int x = 0; x < n; x++) 
    {
        cout << "Salary for employee #" << x + 1 << ": ";
        cin >> ray[x];
    }

    selectionSort(ray, n);

    cout << "\nHere are the salaries sorted from highest to lowest:\n";
    for(int y = 0; y < n; y++) 
    {
        cout << ray[y] << " ";
    }
    cout << endl;

    int target;
    cout << "\nEnter a salary you want to look up: ";
    cin >> target;

    linearSearch(ray, n, target);

    delete[] ray;
    return 0;
}
