// 2. An airline company wants to quickly update its system with flight ticket prices. Use Comb Sort to arrange ticket
// prices from lowest to highest. After sorting, display the cheapest 3 flights available.

#include <iostream>
using namespace std;

// void cSort(int ray[], int size)
// {
//     // modified version of bubble sort
//     const double shrink = 1.3;
//     int gap = size;
//     bool swaps = true;

//     while (gap > 1 || swaps == true)
//     {

//         gap = (int) gap / shrink;

//         // we do it this way int gap = (int) gap / shrink, wherehsrink = 1.30 or 
//         /*
//             if we do it this way 
//             int gap = (gap * 10) / 13
//             both are equivakent and technically the same; 
//         */

//         if (gap < 1)
//         {
//             gap = 1;
//         }
//         swaps = false;

//         for (int m = 0; m + gap < size; m++)
//         {
//             if (ray[m] > ray[m + gap])
//             {
//                 ray[m] = ray[m] ^ ray[m + gap];
//                 ray[m + gap] = ray[m] ^ ray[m + gap];
//                 ray[m] = ray[m] ^ ray[m + gap];
                
//                 swaps = true;
//             }
//         }

//     }
// }

void cSort(int ray[], int size)
{
    const double shrink = 1.30;
    int gap = size;
    bool swaps = true;

    while (gap > 1 || swaps == true)
    {
        gap = (int) gap /shrink;
        swaps = false;
        if (gap < 1)
        {
            gap = 1;
        }

        for (int m = 0; m + gap < size; m++)
        {
            if (ray[m] > ray[m + gap])
            {
                ray[m] = ray[m] ^ ray[m + gap];
                ray[m + gap] = ray[m] ^ ray[m + gap];
                ray[m] = ray[m] ^ ray[m + gap];

                swaps = true;
            }
        }
    }
}

int main(void)
{
    
    int size = 0;
    cout << "Enter the number of ticket prices that you want to enter: " << endl;
    cin >> size;

    int *ray = new int [size];

    cout << "Please enter the ticket prices in your data structure: " << endl;
    for (int m = 0; m < size; m++)
    {
        cout << "Ticket No#0" << m + 1 << ": \n";
        cin >> ray[m]; 
    }

    cSort(ray, 5);

    cout << "Ticket prices of flights sorted in ascending order from lowest to highest: " << endl;
    for (int m = 0; m < size; m++)
    {
        cout << ray[m] << " ";
    }

    cout << endl;

    cout << "Displaying the prices of the three cheapest filghts: "<< endl;
    for (int m = 0; m < 3 && m < size; m++)
    {
        cout << ray[m] << " ";
    }

    delete[] ray;

    return 0;
}