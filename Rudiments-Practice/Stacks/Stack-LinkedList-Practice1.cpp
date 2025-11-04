#include <iostream>
using namespace std;

class Node 
{

    public: 
        int data;
        Node* next;

        Node(int val)
        {
            data = val;
            next = NULL;
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

        ~Stack()
        {

            while (!isEmpty())
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

            cout << val << " successfully pushed onto the stack.\n";
        }

        void pop()
        {

            if (isEmpty())
            {
                cout << "Heap underflow! nothing to pop from the Heap.\n";
                return;
            }

            Node* temp = top;

            top = top->next;

            cout << temp->data << " successfully popped from the stack.\n";
            delete temp;
        }

        int peek(void)
        {
            if (isEmpty())
            {
                cout << "Heap underflow! nothing to peek at.\n";
                return -1;
            }

            return top->data;
        }

        bool isEmpty()
        {
            return (top == nullptr);
        }

        void display(void)
        {
            if (isEmpty())
            {
                cout << "Heap in empty, nothing to display.\n";
                return;
            }

            cout << "Heap elements (top to bottom): " << endl;

            Node* curr = top;

            while (curr != NULL)
            {

                cout << curr->data << "->";
                curr = curr->next;
            }

            cout << "NULL.\n";

            delete curr;
        }

};

int main(void)
{
    
    Stack s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << "Value peeked: " << s1.peek() << endl;

    s1.pop();
    s1.pop();

    cout << "Value peeked: " << s1.peek() << endl;
    s1.pop();
    s1.pop();

    return 0;
}