// 3. An HR manager has a list of employee salaries. Use Selection Sort to sort them in descending order. Then search
// for a specific salary using Linear Search. If multiple employees earn the same salary, return the first and last
// occurrence.
#include <iostream>
using namespace std;

// okay I have figured out something interesting
// below is a correctly written version of the selection sort algorithm, this has the swapping implemented by the xor operarion
/*

But try uncommenting this algorithm out and running this program with these set of values
array size = 6
employee salaries as follows:-
12 23 24 678 1 34
search for the salary 990

the array we would get is (when we print it after implementing the selection sort algorithm is)
678 34 0 23 12 1
when it should be 
678 34 24 23 12 1

Q) Why do we see a zero sneaking into our array?
A) We see a zero at the exact same place where we had an element that did not require a swap 
i.e the element was already in it's correct position in the original array

but since we have used the XOR operation for swapping 
if the element is already in it's correct position that means 
m == li 
so XOR of 2 similar numbers 
ray[m] and ray[li] 
would yield in a zero popping out

Solution when ever we use such algorithms for sorting always avoid using the XOR operation for swapping because that is what causes the issue 
just go with the temp variable method or just use swap() function
*/

// void sSort(int ray[], int size)
// {

//     for (int m = 0; m < size - 1; m++)
//     {

//         int li = m;

//         for (int n = m + 1; n < size; n++)
//         {
//             if (ray[li] < ray[n])
//             {
//                 li = n;
//             }
//         }

//         ray[m] = ray[m] ^ ray[li];
//         ray[li] = ray[m] ^ ray[li];
//         ray[m] = ray[m] ^ ray[li];

//     }

// }

void sSort(int ray[], int size)
{

    for (int m = 0; m < size - 1; m++)
    {
        int li = m;

        for (int n = m + 1; n < size; n++)
        {
            if (ray[n] > ray[li])
            {
                li = n;
            }
        }

        swap(ray[li], ray[m]);
    }
}

// a linear search that searches the entire list and when multiple employees earn the same salary then the first and last occurance of the ssalary 
// are returned

// void lSearch(int ray[], int size, int key)
// {
//     int fOcrFlg = -1; 
//     int lOcrFlg = -1;

//     for (int m = 0; m < size; m++)
//     {
//         if (key == ray[m])
//         {
//             if (fOcrFlg == -1)
//             {
//                 fOcrFlg = m;
//             }
//             else 
//             {
//                 lOcrFlg = m;
//             }
//         }
//     }

//     if (fOcrFlg == -1)
//     {
//         cout << "No employee currently has the salary: " << key << "////\n";
//         return;
//     }

//     if (lOcrFlg == -1)
//     {
//         cout << "There is only one employee with the salary: " << key << ", at index position: " << fOcrFlg << endl;
//         return;
//     }

//     cout << "The first occurance of the Salary: " << key << ", was found at: " << fOcrFlg + 1 << ", index position in array.\n";
//     cout << "The last occurance of the Salary: " << key << ", was found at: " << lOcrFlg + 1 << ", index position in array.\n";

// }

// a linear search with a better approach that solves the same question

void lSearch(int ray[], int size, int key)
{

    int fFlg = -1;
    int lFlg = -1;

    for (int m = 0; m < size; m++)
    {
        if (ray[m] == key)
        {
            if (fFlg == -1)
            {
                fFlg = m;
            }
            lFlg = m;
        }
    }

    if (fFlg == -1)
    {
        cout << "Sorry no employees earn this salary.\n"<< endl;
    }
    else 
    {
        cout << "Yes this salary exists in the record////\n";
        cout << "The first employee with this salary is at position: " << fFlg + 1<< endl;
        cout << "The Last employee with this salary is at position: " << lFlg + 1 << endl;
    }
}

void display(int ray[], int size)
{
    for (int m = 0; m < size; m++)
    {
        cout << ray[m] << " ";
    }
    cout << "\n";
}

int main(void)
{
    
    int size = 0;

    cout << "Enter size of the array: " << endl;
    cin >> size;

    int* salRay = new int [size];

    cout << "Please start populating your data structure with the saalries of your employees.\n";

    for (int m = 0; m < size; m++)
    {
        cout << "Employee No#0" << m + 1 << ": " << endl;
        cin >> salRay[m];
    }

    int salToSearch = 0;

    cout << "Enter the salary that you would like to search for: " << endl;
    cin >> salToSearch;

    sSort(salRay, size);
    display(salRay, size);

    lSearch(salRay, size, salToSearch);
    
    return 0;
}