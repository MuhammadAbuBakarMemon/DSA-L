#include <iostream>
using namespace std;

class MaxHeap()
{

    private:
        int* ray;
        int currCap;
        int currSize;

        MaxHeap(int m) : currSize(0), currCap(m)
        {
            int* ray = new int[currCap];
        }

        void ensureCapacity()
        {
            if (currCap == currSize)
            {

                int newCap = currCap * 2;
                int nray = new int [newCap];
                
                for (int m = 0; m < currSize; m++)
                {
                    narray
                }

            }
        }

};

void insertKeyInMinHeap()
{

}

int main(void)
{
    
    return 0;
}