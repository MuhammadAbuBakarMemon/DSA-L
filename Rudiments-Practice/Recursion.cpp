#include <iostream>
using namespace std;

int func(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else 
    {
        return func(n - 1);
    }
}

void printAge(int n)
{
    if (n < 18)
    {
        cout << "Age under 18: " << n << endl;
        n += 5;
        printAge(n);
    }
}

int main(void)
{

    return 0;
}