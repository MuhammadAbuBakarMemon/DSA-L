#include <iostream>
using namespace std;

int bSearch(int ray[], int size, int valToSearch)
{
    int result = -1;
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {

        int mid = (left + right) / 2;

        if (valToSearch == ray[mid])
        {
            result = mid;
            right = mid - 1;    
            // line 18 basically means that we will continue to search our array's left hand side for any possibilities to obtain the earliest occurance of  
            // our target value 
        }
        else if (valToSearch < ray[mid])
        {
            right = mid - 1;
        }
        else 
        {
            left = mid + 1;
        }

    }

    return result;
}

void printRay(int ray[], int a)
{
    for(int m = 0; m < a; m++)
    {
        cout << ray[m] << " ";
    }

    cout << endl;
}

void bSearchOutput(int idx)
{
    if (idx == -1)
    {
        cout << "No instance of the value to search was found in your populated data structure////\n";
    }
    else 
    {
        cout << "The earliest occurance of the value to search was obtained at the index position [" << idx << "]\n";
    }
}

int main(void)
{

    // int ray[5] {5, 2, 1, 4, 3}
    // this will not work because binary search requires the array to be sorted////
    // int ray[] = {5, 2, 3, 1, 4};

    int ray[] {1, 2, 3, 4, 5};
    printRay(ray, 5);
    bSearchOutput(bSearch(ray, 5, 2));
    bSearchOutput(bSearch(ray, 5, 23));
    
    return 0;
}