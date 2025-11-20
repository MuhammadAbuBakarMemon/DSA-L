#include <iostream>
using namespace std;

class Node
{

    public:
        int data;
        Node* next;

        Node(int m)
        {
            data = m;
            next = NULL;
        }

};

/*
The speciality of a queue is that it implements all enqueue(), dequeue(), and peek() functions wiht a 
time complexity of O(1)
*/

class Queue
{

    private:
        Node* front;
        Node* rear;

    public: 

        Queue()
        {
            front = rear = NULL;
        }

        bool isEmpty()
        {
            return (front == NULL);
        }

        // do not think much a Queue implemented via a Linked List can never be full....

        // bool isFull()
        // {

        // }

        void enqueue(int m)
        {
            Node* n = new Node(m);

            if (isEmpty())
            {
                front = rear = n;
            }
            else 
            {
                rear->next = n;
                rear = n;
            }
            
            cout << "Enqueued: " << m << "." << endl;

        }

        int peek()
        {
            if (isEmpty())
            {
                cout << "Queue is empty can not peek." << endl;
                return -1;
            }
            else 
            {
                return front->data;
            }
        }

        // An edge case to remember when dequeuing is 
        void dequeue()
        {

            if (isEmpty())
            {
                cout << "Queue is empty, hence dequeue operation fails." << endl;
            }
            else 
            {
                cout << "Dequeued: " << front->data << "." << endl;
                Node* temp = front;
                front = front->next;

                // This is an edge case 

                /*
                
                See this is c++ not java or pyhton 

                once we dynamically allocate a memory via new we need to ensure we delete that memory, because otherwise we have 
                a critical memory leak in our program, when all the queue was filled and we one by one dequeued an element we reached the rear of the 
                queue 
                once this happens the front and rear both point to the last Node in the queue 
                now performing a dequeue function means that the 
                front pointer = NULL
                rear still points to the node we just deleted 
                rear becomes a dangling pointer, as we deleted temp pointer which also pointed to the same node 
                so when we deleted temp, this pointer and the node it pointed too both got deleted, but rear still points to a the invalid 
                memory address and now  becomes a dangling pointer   
                
                */

                // Ensure if queue is now empty, then rear is also null
                if (front == NULL)
                {
                    rear = nullptr;
                }

                delete temp;
            }

            /*
            But didn't the rear pointer already become null when I deleted the temporary pointer?
            
            nope delete temp destroys the house (the memory) but it does not erase the addres written in your address book for the rear pointer 
            so rear is a dnagling pointer as it is pointing to a location in the memory that no longer belongs to our program 

            */

        }

        void dispQueue()
        {

            if (isEmpty())
            {
                cout << "Queue is empty, hence printing operation fails." << endl;
            }
            else 
            {
                Node* qTrav = front;

                while (qTrav->next != NULL)
                {
                    cout << qTrav->data << "->";
                    qTrav = qTrav->next;
                }
                cout << qTrav->data;
                cout << "." << endl;
            }

        }

};

int main(void)
{
    Queue q1;

    q1.dispQueue();

    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);

    cout << "Peeked value: " << q1.peek() << endl;

    q1.enqueue(4);
    q1.enqueue(5);

    q1.dispQueue();

    // q1.peek();
    
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();

    cout << "Peeked value: " << q1.peek() << endl;

    q1.dequeue();

    q1.enqueue(30);
    q1.enqueue(69);

    q1.dispQueue();

    return 0;
}