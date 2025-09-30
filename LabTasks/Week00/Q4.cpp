// Q4. A weather station wants to store temperatures for a week. Write a C++ program that
// dynamically allocates an array of 7 double values using a pointer. Ask the user to input daily
// temperatures, then display them along with the average temperature. Finally, free the memory.

#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{

    double *ray = new double[7];

    cout << "Please start ntering the daily temperatures: " << endl;

    for (int m = 0; m < 7; m++)
    {
        cout << "Day Number#0" << m + 1 <<  ": " << endl;
        cin >> *(ray+m);
    }

    cout << "Temperatures for all days successfully feeded...." << endl;

    double avg = 0.00;

    for (int m = 0; m < 7; m++)
    {
        avg += ray[m];
    }

    cout << "The average temperture is: " << fixed << setprecision(2) << (avg/7) << endl;

    for (int m = 0; m < 7; m++)
    {
        cout << "Temperature for day - 0" << m << ": " << ray[m] << endl;
    }

    delete[] ray;

    return 0;
}