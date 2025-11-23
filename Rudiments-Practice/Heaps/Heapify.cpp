/*
this version builds a heap from scratch using an array in sequential order and then uses the heapify function from the 
last non-leaf element all the way upto the top most priority element in the heap ensuring the heap structure 

This takes O(n) time to produce an heap for us derived from Floyd's algorithm 

-----------------------------------------------------------------------------------------

Heapify is basically the opposite of what we used to do after insertion in a heap 
we used to insert an element in the heap and then we used to perform the swim operation continously going upwards 
to reach the point when either k <= 0 or the heap had maintained it's structure in accodance with if it was a min 
heap or a max heap 

But here we start from the end most index occupying non-leaf element and then we iterate from that element to the 
top  most elemnt in the heap performing the sink() operation assuring that subtree at that non-leaf index position 
is following our heap structure 

*/

#include <iostream>
#include <algorithm>
using namespace std;

class MaxHeap 
{
    private:
        int* ray;
        int heapsize;
        int capacity;

        int gPI(int m)
        {
            return ((m - 1) / 2);
        }
        
        int gLCI(int m )
        {
            return ( (2* m) + 1);
        }

        int gRCI(int m)
        {
            return ( (2 * m) + 2);
        }

        void resize(int newcapacity)
        {
            int* nray = new int [newcapacity];

            // This was an error, we will always copy till the number of elemnts in our heap which will indeed be the heap's size
            // for (int m = 0; m < capacity; m++)
            for (int m = 0; m < heapsize; m++)
            {
                nray[m] = ray[m];
            }

            delete[] ray;
            capacity = newcapacity;
            ray = nray;
        }

        bool isEmpty()
        {
            return (heapsize == 0);
        }
        
        // heapify that oerates on a given array with a time complexity of O(n)
        void heapify(int m)
        {
            int lar = m;
            int left = gLCI(m);
            int right = gRCI(m);

            if (left < heapsize && ray[lar] < ray[left])
            {
                lar = left;
            }

            if (right < heapsize && ray[lar] < ray[right])
            {
                lar = right;
            }

            if (lar != m)
            {
                swap(ray[lar], ray[m]);
                heapify(lar);
            }
        }

        // we are choosing not to write our swim function here but inside of our inserting a value into the heap wala function 

        public: 

            int getHS()
            {
                return heapsize;
            }

            MaxHeap(int m) : heapsize(0), capacity(m)
            {
                ray = new int [capacity];
            }

            ~MaxHeap()
            {
                cout << "The Heap was destroyed,,,," << endl;
                delete[] ray;
            }

            void buildHeap(int inp[], int x)
            {
                if (x > capacity)
                {
                    resize(x);
                }

                for (int m = 0; m < x; m++)
                {
                    ray[m] = inp[m];
                }
                heapsize = x;

                // now we move on towards calling our heapify function once we have built our heap
                int stIdx = gPI(heapsize - 1);

                for (int m = stIdx; m >= 0; m--)
                {
                    heapify(m);
                }
            }

            // Insertion function standard O(log n) ki insertion time 
            void insertInHeap(int val)
            {
                if (heapsize == capacity)
                {
                    // when inserting there are 2 cases for resizing 
                    /*
                    1) multiply the current size by 2
                    2) is that sort of an heap that doesn't have any elements then multiplying the size by 2 is also going to give us 0 space 
                    to add in out elements 

                    so in accordance with what we have, we should take appropriate resizing measures into action  
                    */

                    resize(capacity == 0 ? 1 : 2 * capacity);
                }

                int temp = heapsize;
                ray[heapsize++] = val;

                // this is the swin function
                while (temp > 0 && ray[temp] > ray[gPI(temp)])
                {
                    swap(ray[temp], ray[gPI(temp)]);
                    temp = gPI(temp);
                }

            }

            int extractMax()
            {
                if(isEmpty())
                {
                    cout << "Error, no element exist in hea, therefore; extraction not possible." << endl;
                    return - 1;
                }

                int valToRet = ray[0];
                swap(ray[0], ray[heapsize - 1]);
                heapsize--;

                heapify(0);
                return valToRet;
            }

            void printHeap()
            {
                for (int m = 0; m < heapsize; m++)
                {
                    cout << ray[m] << " ";
                }
                cout << endl;
            }


};

int main(void)
{
    
    MaxHeap H(20);

    int data[] = {1, 2, 3, 56, 23, 11, 4, 0, 34, 6999, 30, 29, 81};
    int size = sizeof(data)/sizeof(data[0]);

    cout << "Printing elements of current array: " << endl;
    for (int m = 0; m < size; m++)
    {
        cout << *(data+m) << " ";
    } 
    cout << endl;

    cout << "Building Heap from this given input array: " << endl;
    H.buildHeap(data, size);

    cout << "Heapified Array: " << endl;
    H.printHeap();

    while (H.getHS() != 0)
    {
        cout << "Extract Max: " << H.extractMax() << endl;
        // cout << "Remaining: " << endl;
        // H.printHeap();
    }
    return 0;
}