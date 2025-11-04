#include <iostream>
using namespace std;

// Merge Sort works on divide and conquer

void Merge(int* ray, int start, int mid, int end)
{

    // this line commented below is an error
    // int *temp[end];
    // This line is basically declaring an array of poinnters not an array of integers

    // int temp [end - start + 1];

    // or we may do this 
    int n = end - start + 1;
    int* temp = new int[n];

    int i = start;
    int j = mid + 1;
    int iterator = 0;

    while (i <= mid && j <= end)
    {
        if (ray[i] < ray[j])
        {
            temp[iterator++] = ray[i++];
        }
        else 
        {
            temp[iterator++] = ray[j++];
        }
    }

    while (i <= mid)
    {
        temp[iterator++] = ray[i++]; 
    }

    while (j <= end)
    {
        temp[iterator++] = ray[j++];
    }

    for (int m = 0; m < iterator; m++)
    {
        ray[start + m] = temp[m];
    }

    delete[] temp;

}

void MergeSort(int* ray, int start, int end)
{

    if (start < end)
    {
        int mid = start + (end - start)/2;

        MergeSort(ray, start, mid);
        MergeSort(ray, mid + 1, end);

        Merge(ray, start, mid, end);

    }
}

void printRay(int* ray, int size)
{
    for (int m = 0; m < size; m++)
    {
        cout << ray[m] << " ";
    }

    cout << endl;
}

int main(void)
{
    
    int ray[] = {5, 2, 9, 1, 6, 3, 30, 23};
    int n = sizeof(ray) / sizeof(ray[0]);

    cout << "Before Sorting: " << endl;
    printRay(ray, n);

    cout << "\n";

    MergeSort(ray, 0, n - 1);

    cout << "After Sorting: " << endl;
    printRay(ray, n);

    return 0;
}

/*

I basically have a question here why can I not use 
array_name.size() to compute out the size of / the number of elements in my array ?

In the code above I have used C-style arrays that basically decay to pointers when passed into fucntions
once that happens the compiler no longerr knows their size 
therefore we can not compute the size of the arrays just by using .size() funxtion 

Had we used C++ container objects 
like std::vectors std::array std::string
then it would have been possible for us to use that function as c++ only provides that functoon for container type objects 

Because coantainers like vector store both the 
the pointer to the data and 
the size and capacity 
so .size() is actually a member fu;nction that returns the number of elements stored

*/