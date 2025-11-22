#include <iostream>
using namespace std;

void set(int e, int pos, int ray[], int s)
{
    if (pos < 0 || pos >= s)
    {
        cout << "Boundary Error...." << endl;
        cout << "Can not insert element because of out of bunds indexing...." << endl;
    }
    else 
    {
        ray[pos] = e;

        cout << "Insertion Successful in safe array...." << endl;
    }
}
int main(void)
{
    
    int size = 5;

    int ray[size] = {1, 2, 3, 4, 5};
    set(3, 2, ray, size);
    set(5, 5, ray, size);

    return 0;
}