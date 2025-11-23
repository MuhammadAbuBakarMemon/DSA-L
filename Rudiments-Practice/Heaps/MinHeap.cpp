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