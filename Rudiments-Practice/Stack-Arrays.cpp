#include <iostream>
using namespace std;

class Stack 
{

    private: 
        int* ray;
        int top;
        int capacity;

    public: 

    Stack (int size) : capacity(size)
    {
        ray = new int [capacity];
        top = -1;
    }

    ~Stack()
    {
        delete[] ray;
        cout << "Destructor for the stack was called...." << endl;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack overflow, can not push " << val << endl;
            return;
        }
        
            ray[++top] = val;
            cout << val << " successfully pushed onto the stack...." << endl;

    }

    int pop(void)
    {

        if (isEmpty())
        {
            cout << "Stack underflow! Nothing to pop....\n";
            return -1;
        }

        int temp = ray[top];
        top--;

        cout << temp << " Successfully popped from the stack....\n";
        return temp;
    }

    int peek()
    {

        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return -1;
        }

        return ray[top];

    }

    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == capacity - 1);
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty....\n";
            return;
        }

        cout << "Stack elemenets: " << endl;
        for (int m = 0; m <= top; m++)
        {
            cout << ray[m] << " ";
        }

        cout << endl;

    }


};

int main(void)
{
    
    Stack s1(5);

    s1.push(5);
    s1.push(10);
    s1.push(15);
    s1.push(20);
    s1.push(25);
    s1.push(30);
    cout << endl;

    cout << "value peeked: " << s1.peek() << endl;

    s1.pop();
    s1.pop();
    s1.pop();


    cout << "Value peeked: " << s1.peek() << endl;

    return 0;
}