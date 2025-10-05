// 1. A list of students’ exam score is given. First, arrange the scores in ascending order using Insertion Sort. Then,
// allow the teacher to search for a particular student’s score using Binary Search. If the score exists, display the
// student’s rank. Otherwise, show "Score not found".

#include <iostream>
using namespace std;

void iSort(int ray[], int size)
{
    for (int m = 1; m < size; m++)
    {
        int temp = ray[m];
        int prev = m - 1;

        while (prev >= 0 && ray[prev] > temp)
        {
            ray[prev + 1] = ray[prev];
            prev--;
        }
        ray[prev + 1] = temp;
    }
}

int bSearch(int ray[], int size , int key)
{

    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (ray[mid] ==  key) return mid;
        else if (key > ray[mid]) left = mid + 1;
        else right = mid - 1;
    }

    return -1; // the algorithm return -1 when the element we are searching for is not found in the array
}

int main(void)
{
 
    int size = 0;

    cout << "Enter the number of students is class?\n";
    cin >> size;

    int *ray = new int [size];

    cout << "Enter the scores of your students please: " << endl;
    for (int m = 0; m < size; m++)
    {
        cout << "Student Number#0" << m + 1 << ": \n";
        cin >> *(ray+m); 
    }

    iSort(ray, 5);

    cout << "Scores in ascending order: " << endl;
    for (int m = 0; m < size; m++)
    {
        cout << ray[m] << " ";
    }
    cout << "\n";

    int valToSearch = 0;

    cout << "Enter the score you want to search for: \n";
    cin >> valToSearch;
    
    int result = bSearch(ray, size, valToSearch);

    if (result == -1)
    {
        cout << "Score not found////" << endl;
    }
    else 
    {
        cout << "The rank of the student with the score [" << valToSearch << "] is: " << size - (result) << endl;
    }

    delete[] ray;

    return 0;
}