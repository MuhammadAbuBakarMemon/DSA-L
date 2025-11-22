#include <iostream>
#include <algorithm>
// this library gets for us the swap() function 
using namespace std;

class MaxHeap
{

    private:
        int* ray;
        int currCap;
        int currSize;

        void ensureCapacity()
        {
            if (currCap == currSize)
            {

                int newCap = currCap * 2;
                int* nray = new int [newCap];
                
                for (int m = 0; m < currSize; m++)
                {
                    nray[m] = ray[m];
                }

                delete[] ray;

                ray = nray;
                currCap = newCap;

            }
        }

        // Time for writing those helper functions 

        int getParentIndex(int m) 
        {
            return (m - 1) / 2;
        }

        int getLeftChildIdx(int m)
        {
            return ((2 * m) + 1);
        }

        int getRightChildIdx(int m)
        {
            return ((2 * m) + 2);
        }

        // this iterates on a loop as we go from bottom to top
        void heapifyUp(int m)
        {

            while (m > 0 && ray[getParentIndex(m)] < ray[m])
            {
                swap(ray[getParentIndex(m)], ray[m]);

                m = getParentIndex(m);
            }
        }

        // this operates recursively as we go from top to bottom 
        void heapifyDown(int m)
        {
            int lar = m;
            int left = getLeftChildIdx(m);
            int right = getRightChildIdx(m);

            if (left < currSize && ray[left] > ray[lar])
            {
                lar = left; 
            }
            
            if (right < currSize && ray[right] > ray[lar])
            {
                lar = right;
            }

            if (lar != m)
            {
                swap(ray[lar], ray[m]);
                heapifyDown(lar);
            }

        }

        public:

            MaxHeap(int m) : currSize(0), currCap(m)
            {
                ray = new int[currCap];
            }

            ~MaxHeap()
            {
                delete[] ray;
            }

            bool isEmpty()
            {
                return (currSize == 0);
            }

            int size()
            {
                return currSize;
            }

            void insertInMaxHeap(int m)
            {
                ensureCapacity();
                ray[currSize++] = m;
                heapifyUp(currSize - 1);
            }

            // returnsthe maximum element without returning it 
            int top()
            {
                if (isEmpty())
                {
                    cerr << "Error! Heap is empty. Can not  get top element. Returning 0." << endl;
                    return -1;
                }

                return ray[0];
            }

            void deleteFromMaxHeap()
            {

                if (isEmpty())
                {
                    cerr << "Error!, the heap is empty so deletion opertion can not be performed." << endl;
                    return;
                }

                swap(ray[0], ray[currSize - 1]);
                currSize--;

                if (!isEmpty())
                {
                    heapifyDown(0);
                }

                cout << "Element: " << ray[currSize] << " successfully deleted from the heap...." << endl; 

            }

           

};

int main(void)
{
    
    MaxHeap myMaxHeap(5);

    cout << "Max Heap operations array based...." << endl;
    cout << "Is empty: " << (myMaxHeap.isEmpty() ? "Yes" : "No") << "\n";

    myMaxHeap.insertInMaxHeap(23);
    myMaxHeap.insertInMaxHeap(21);
    myMaxHeap.insertInMaxHeap(5);
    myMaxHeap.insertInMaxHeap(34);
    myMaxHeap.insertInMaxHeap(28);
    myMaxHeap.insertInMaxHeap(69);
    myMaxHeap.insertInMaxHeap(0);
    myMaxHeap.insertInMaxHeap(37);

    cout << "After inseritng these elements (23, 21, 5, 34, 28, 69, 0, 37)" << endl;
    cout << "Heap size is: " << myMaxHeap.size() << endl; 

    cout << "The Max Element currently in our heap is: " << myMaxHeap.top() << endl;

    myMaxHeap.deleteFromMaxHeap();

    cout << "The New Max Element currently in our heap is: " << myMaxHeap.top() << endl;

    cout << "Emptying the heap: " << endl;
    while (!myMaxHeap.isEmpty())
    {
        myMaxHeap.deleteFromMaxHeap();
    }

   cout << "The Max Element currently in our heap is: " << myMaxHeap.top() << endl;

cout << "Attempting to delete from an empty heap: " << endl;
   myMaxHeap.deleteFromMaxHeap();

    return 0;
}