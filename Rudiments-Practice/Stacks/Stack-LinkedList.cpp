#include <iostream>
using namespace std;

/*

When we are implementing a stack we ensure that the operation of push(), pop() and peek() all operate with a time-complexity of O(1)

*/

class Node 
{

    public:
        int data;
        Node* next;
    
        Node(int val)
        {
            data = val;
            next = nullptr;
        }
};

class Stack 
{

    private:
        Node* top;

    public:     
        Stack()
        {
            top = nullptr;
        }

        ~Stack(void)
        {
            while(!isEmpty())
            {
                pop();
            }

            cout << "Stack was destroyed.\n";
        }

        void push(int val)
        {
            Node* newNode = new Node(val);

            newNode->next = top;
            top = newNode;

            cout << val << " Successfully pushed onto the stack.\n";
        }

        void pop()
        {

            if (isEmpty())
            {
                cout << "Heap underflow, can not perform pop() operation.\n"; 
                return;
            }

            Node* temp = top;
            top = top->next;

            cout << temp->data << " succcessfully popped from the stack.\n";
            delete temp;

        }

        int peek(void)
        {

            if (isEmpty())
            {
                cout << "Heap underflow! nothing to peek.\n";
                return -1;
            }

            return top->data;
        }

        bool isEmpty(void)
        {
            return (top == nullptr);
        }

        void display()
        {
            if (isEmpty())
            {
                cout << "Heap is empty.\n";
                return;
            }

            cout << "\nHeap elements (top to bottom): " << endl;

            Node *curr = top;

            while (curr != nullptr)
            {
                cout << curr->data << "->";
                curr = curr->next; 
            }

            cout << "NULL\n";
            
        }
};

int main(void)
{
    
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "value peeked: " << s.peek() << endl;

    s.pop();
    s.pop();

    cout << "value peeked: " << s.peek() << endl;

    s.pop();

    s.pop();

    return 0;
}