#include <iostream>
int main(void)
{

    int a = 30;
    int * ptr = nullptr; // pointer declaration and initialization 
    ptr = &a;           // storing address of a in ptr

    std::cout << "Value of a: " << a << std::endl;
    std::cout << "Value in ptr (address of a): " << ptr << "\n";
    std::cout << "Address of a: " << ptr << std::endl;
    std::cout << "Value at address in ptr (value of variable a): " << *(ptr) << std::endl;

    return 0;
}