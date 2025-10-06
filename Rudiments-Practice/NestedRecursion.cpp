#include <iostream>
using namespace std;

int nestFunc(int n)
{
    if (n > 100) return n - 10;

    return nestFunc(nestFunc(n + 11));
}

int main(void)
{
    int r = 0;
    r = nestFunc(95);
    cout << r << endl;
    return 0;
}