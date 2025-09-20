#include <iostream>
using namespace std;

int main() 
{
    
    int n;

    cout << "Enter the size of your dynamic array: " << endl;
    cin >> n;
    
    int* ray = new int[n];
    
    for (int x = 0; x < n; x++) 
    {
        std::cout << "Ray[" << x + 1 << "] - ";
        std::cin >> ray[x];
    }
    
    for (int x = 0; x < n - 1; x++) 
    {
        for (int y = 0; y < n - x - 1; y++) 
        {
            if (ray[y] > ray[y + 1]) 
            {
                int temp   = ray[y];
                ray[y]     = ray[y + 1];
                ray[y + 1] = temp;
            }
        }
    }
    

    cout << endl << "Sorted Array after application of bubble sort: " << endl;

    for (int x = 0; x < n; x++) 
    {
        cout << ray[x] << " ";
    }
    
    delete[] ray;
    
    return 0;
}
