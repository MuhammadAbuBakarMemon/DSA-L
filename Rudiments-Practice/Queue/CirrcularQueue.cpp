#include <iostream>
using namespace std;

/*
Linear Queue may or may not have fixed size, but cirrcular queue always has a fixed size because only then we would have the idea of when to start 
repeatedly traversing the index positions of the cirrrcular queue from the start 
hence why we use an array to implement our cirrcular queues

To implement a cirrcular quque we have to implement these 3 functions 
enqueue, dequeue, front
all with a time complexity of O(1);
*/

class Queue 
{

    private:
        int cap;
        int front;
        int rear;
        int* ray;

    public: 
        
        Queue(int c) : cap(c)
        {
            ray = new int [cap];
            front = rear = -1;
        }

        void enqueue(int m)
        {
            if (isFUll())
            {
                cout << "Queue is full." << endl;
            }
            else 
            {
                if (isEmpty())
                {
                    rear = front = 0;   
                }
                else 
                {
                    rear = (rear + 1) % cap;
                }

                ray[rear] = m;
                cout << "Enqueued: " << m << endl;
            }

        }

        void dequeue()
        {
            if (isEmpty())
            {
                cout << "Queue already empty...." << endl;
                return;
            }

            cout << "Dequeued: " << ray[front] << endl;
           
            if (rear == front)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % cap;
            }
        }

        bool isFUll()
        {
            return (((rear + 1) % cap) == front);
        }

        bool isEmpty()
        {
            // return (front == rear); wrong 
            return (front == -1); 
        }

        void dispQueue()
        {

            if (isEmpty())
            {
                cout << "Queue is empty." << endl;
                return;
            }

            int trav = front;

            while (trav != rear)
            {
                cout << ray[trav] << "->";
                trav = (trav + 1) % cap;
            }
            cout << ray[trav] << endl;

        }

};

int main(void)
{
    
    Queue q1(5);

    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);

    q1.dispQueue();

    q1.dequeue();
    q1.dequeue();
    q1.dequeue();

    q1.enqueue(30);

    q1.dispQueue();

    return 0;
}