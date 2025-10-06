#include <iostream>
using namespace std;

/*
Time Complexity = total cases * workdone in each case 
total cases = 
2^n because we have n elements in our array, the possible number of subsets we can have are 2^n
and since to reach all of these individual cases 
we must reach the bottom most leaf whilst traversing our tree 
which is the height of our tree, and this will be equal to the number of elements inn our original array
so we haver to traverse n times down the tree to reach each one of our leafs/cases 
so total cases = n * 2^n

and assuming that we neglect the base case of our recursion and that the amount of work done in each case is assumed to be 
O(1) - constant time 

we get 
Time Complexity computed out as = 
(n * 2^n) * O(1)
*/

// void printSubsetsRay(int ray[], int os, int ans[], int s, int x)
// {

//     if (x == os)
//     {
//         // when base case hits we print out all of the elements in our array 
//         for (int m = 0; m < s; m++)
//         {
//             if (ans[m] != 0)
//             {
//                 cout << ans[m] << " ";
//             }
//         }
//         cout << endl;
//         return;
//     }

//     // inclusion step
//     ans[s] = ray[x];
//     printSubsetsRay(ray, os, ans, s + 1, x + 1);

//     // exclusion step
//     ans[s] = 0;
//     printSubsetsRay(ray, os, ans, s, x + 1);
// }

void printSubRay(int ray[], int size, int ans[], int asize, int x)
{

    if (size == x)
    {
        for (int m = 0; m < asize; m++)
        {
            if (ans[m] != 0)
            {
                cout << ans[m] << " ";
            }
        }
        cout << endl;
        return;
    }

    // inclusion step
    ans[asize] = ray[x];
    printSubRay(ray, size, ans, asize + 1, x + 1);

    // exclusion step
    ans[asize] = 0;
    printSubRay(ray, size, ans, asize, x + 1);

}

int main(void)
{
    
    int ray[] = {1, 2, 3};
    int os = 3;
    int ans[3] = {0};

    printSubsetsRay(ray, os, ans, 0, 0);
    return 0;
}