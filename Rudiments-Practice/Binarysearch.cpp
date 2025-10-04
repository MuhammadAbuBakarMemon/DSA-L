#include <iostream>
using namespace std;

void bSearch(int ray[], int size, int target)
{
 
    int left = 0;
    int right = size - 1;

    int result = -1;

    while (left <= right)
    {

        int mid = (left + right) / 2;

        if (target == ray[mid])
        {
            result = mid;
            break;
        }
        else if (target < ray[mid])
        {
            right = mid - 1;
        }
        else 
        {
            left = mid + 1;
        }

    }

    if (result == -1)
    {
        cout << "Target element [" << target << "] could not be found in Array////" << endl;  
    }
    else 
    {
        cout << "Target element [" << target << "] found in Array at index position [" << result << "]\n";
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

    int ray[] = {5, 2, 3, 1, 4};
    printRay(ray, 5);
    bSearch(ray, 5, 4);
    bSearch(ray, 5, 23);
    
    return 0;
}