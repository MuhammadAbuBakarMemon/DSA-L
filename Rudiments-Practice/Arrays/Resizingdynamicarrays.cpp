#include <iostream>
using namespace std;

int* resizeRay(int ray[], int os, int ns)
{

    if (ns == os)
    {
        return ray;
    }

    int* nray = new int [ns];
    int limit = (ns > os) ? os : ns;

    for (int m = 0; m < limit; m++)
    {
        nray[m] = ray[m];
    }

    delete[] ray;

    return nray;

}

int main(void)
{
    
    int size = 5;
    int * ray = new int[size] {1, 2, 3, 4, 5};

    cout << "Array Elements: " << endl;

    for (int m = 0; m < size; m++)
    {
        cout << ray[m] << " ";
    }

    int newsize = 8;

    ray = resizeRay(ray, size, newsize);
    
    for (int m = size; m < newsize; m++)
    {
        ray[m] = m + 1;
    }

    cout << endl << "Resized to bigger array: " << endl;

    for(int m = 0; m < newsize; m++) cout << ray[m] << " ";

    size =  newsize;
    newsize = 3;

    ray = resizeRay(ray, size, newsize);

    cout << endl << "Reszied to smaller array: " << endl;

    for (int m = 0; m < newsize; m++) cout << ray[m] << " ";

    return 0;
}