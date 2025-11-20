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
                return 0;
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

                if (front == NULL)
                {
                    rear = nullptr;
                }

                delete temp;
            }

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