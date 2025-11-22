#include <iostream>
using namespace std;

// int iSearch(int ray[], int size, int key)
// {
//     int low = 0;
//     int high = size - 1;
    
//     while (low <= high && key >= ray[low] && key <= ray[high])
//     {
//         if (low == high)
//         {
//             if (ray[low] == key) return low;
//             return -1;
//         }

//         int pos = low + ( (key - ray[low]) / (ray[high] - ray[low]) * (high - low) );

//         if (ray[pos] == key)
//         {
//             return pos;
//         }
//         else if (ray[pos] < key)
//         {
//             low = pos + 1;
//         }
//         else 
//         {
//             high = pos - 1;
//         }
//     }
//     return -1;
// }

int iSearch(int ray[], int size, int key)
{

    int low = 0;
    int high = size - 1;

    while (low <= high && key >= ray[low] && key <= ray[high])
    {
        if (high == low)
        {
            if (ray[low] == key) return low;
            return -1;
        }

        // returning -1 basicallly tells me that no occurance of the key was found in my array

        int pos = low + ( (key - ray[low]) / (ray[high] - ray[low]) * (high - low));

        if (key == ray[pos]) return pos;
        else if (key >= ray[pos]) low = pos + 1;
        else high = pos - 1;
    }
    return - 1;

}

void resISearch(int val)
{
    if (val == -1)
    {
        cout << "No occurance of the key value was found in the array///" << endl;
    }
    else 
    {
        cout << "Key value found at index: " << val << endl;
    }
}

void printRay(int ray[], int a)
{
    for(int m = 0; m < a; m++)
    {
        cout << ray[m] << " ";
    }

    cout << endl;
}

int main(void)
{

    // int ray[5] {5, 2, 1, 4, 3}
    // this will not work because binary search requires the array to be sorted////
    // int ray[] = {5, 2, 3, 1, 4};

    int ray[] {1, 2, 3, 4, 5};
    printRay(ray, 5);
    resISearch(iSearch(ray, 5, 4));
    resISearch(iSearch(ray, 5, 12)); 
    return 0;
}