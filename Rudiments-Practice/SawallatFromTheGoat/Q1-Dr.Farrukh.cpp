// That's a very common point of confusion when working with dynamic arrays and index boundaries!The short answer is no, ray[currSize] does not contain the deleted element after the currSize-- operation.Here's why, explained step-by-step:🧐 Indexing and Deletion ExplainedLet's assume the heap currently has 8 elements, so currSize is 8.Step 1: State Before SwapcurrSize = 8.The valid elements are in indices $\text{ray}[0]$ through $\text{ray}[7]$.The element we want to delete (the minimum) is at $\text{ray}[0]$.The last element is at $\text{ray}[\mathbf{currSize - 1}]$, which is $\text{ray}[7]$.Step 2: The SwapYou execute:C++swap(ray[0], ray[currSize - 1]); 
// // swap(ray[0], ray[7])
// The original minimum element is now at index 7.The original last element is now at index 0.Step 3: Decrementing the SizeYou execute:C++currSize--;
// currSize is now 7.The valid, active heap elements are now considered to be in indices $\text{ray}[0]$ through $\text{ray}[6]$.Step 4: The Incorrect Index AccessYou execute your print statement:C++cout << "Deleted element: " << ray[currSize] << " successfully from Heap." << endl;
// // cout << "Deleted element: " << ray[7] << " successfully from Heap." << endl;
// The index you are accessing is $\text{ray}[\mathbf{7}]$.Based on Step 2, the element at $\text{ray}[7]$ is indeed the deleted element (the original minimum).🚨 THE REAL PROBLEM: Array Bounds ⚠️While in your specific logic flow, ray[currSize] happened to hold the deleted value because of the preceding swap and decrement, relying on this is a dangerous bug because it accesses memory outside the logical bounds of the current heap.When currSize is 7, the valid indices for the active heap are $0$ to $6$ (currSize - 1).Accessing $\text{ray}[7]$ is accessing the first inactive/dead slot in the heap array. This index is about to be overwritten in the next insertion or could be flagged by memory sanitizers.The correct and safe way to print the deleted value is to capture it before the size is reduced:C++// 1. Capture the element before swapping it out of the active heap
// int deletedElement = ray[0]; 

// swap(ray[0], ray[currSize - 1]);
// currSize--; 

// // 2. Print the captured value (guaranteed to be correct and safe)
// cout << "Deleted element: " << deletedElement << " successfully from Heap." << endl;


#include <iostream>
#include <algorithm>
using namespace std;

class MinHeap
{

    private:
        int* ray;
        int currSize;
        int currCap;

        void resizeHeap()
        {
            if (currCap == currSize)
            {
                int newCap = 2 * currCap;

                int *nray  = new int [newCap];

                for (int m = 0; m < currSize; m++)
                {
                    nray[m]= ray[m];
                }

                delete[] ray;

                ray = nray;
                currCap = newCap;
            }
        }

        int gPI(int m)
        {
            return ((m - 1)  / 2);
        }

        int gLCI(int m)
        {
            return ((2 * m) + 1);
        }

        int gRCI(int m)
        {
            return ((2 * m) + 2);
        }

        void Swim(int m)
        {
            while  (m > 0 && ray[gPI(m)] > ray[m])
            {
                swap(ray[m], ray[gPI(m)]);

                m = gPI(m);
            }
        }

        void Sink(int m)
        {

            int small = m;
            int right = gRCI(m);
            int left = gLCI(m);

            if (left < currSize && ray[left] < ray[small])
            {
                small = left;
            }

            if (right < currSize && ray[right] < ray[small])
            {
                small = right;
            }

            if (small != m)
            {
                swap(ray[small], ray[m]);
                Sink(small);
            }

        }

        public:

            MinHeap(int m) : currSize(0), currCap(m)
            {
                ray = new int [currCap];
            }

            ~MinHeap()
            {
                delete[] ray;
            }

            bool isEmpty()
            {
                return (currSize == 0);
            }

            void insertInMinHeap(int m)
            {
                resizeHeap();
                ray[currSize++] = m;
                Swim(currSize - 1);
            }

            int top()
            {
                if (isEmpty())
                {
                    cerr << "Heap is empty, can not perform peek operation." << endl;
                    return -1;
                }

                return ray[0];
            }

            void deleteFromMinHeap()
            {

                if (isEmpty())
                {
                    cerr << "Error! Heap is empty, can not perform delete operation." << endl;
                    return;
                }

                swap(ray[0], ray[currSize - 1]);
                currSize--;

                // This is a condition on which I  regularly missout
                // this is the case when we perform deletion on just one element in the heap
                if (!isEmpty())
                {
                    Sink(0);
                }

                cout << "Deleted element: " << ray[currSize] << " successfully from Heap." << endl;

            }

};

int main(void)
{
    
    MinHeap myMinHeap(5);

    myMinHeap.insertInMinHeap(70034);
    myMinHeap.insertInMinHeap(25);
    myMinHeap.insertInMinHeap(2845);
    myMinHeap.insertInMinHeap(0);
    myMinHeap.insertInMinHeap(1);

    cout << "Peeking at the top of the Heap: " << myMinHeap.top() << endl;

    myMinHeap.insertInMinHeap(2);
    myMinHeap.insertInMinHeap(143);
    myMinHeap.insertInMinHeap(11);

    cout << "Peeking at the top of the Heap: " << myMinHeap.top() << endl;

    while (!myMinHeap.isEmpty())
    {
        myMinHeap.deleteFromMinHeap();
        cout << "Peeking at the top of the Heap: " << myMinHeap.top() << endl;
    }

    myMinHeap.deleteFromMinHeap();
    
    return 0;
}