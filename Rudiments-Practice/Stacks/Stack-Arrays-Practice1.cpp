#include <iostream>
using namespace std;

class Stack
{
    private:
        int cap;
        int top;
        int* ray;

    public: 

    Stack(int m)
    {
        cap = m;
        top = -1;
        ray = new int [cap];
    }

    ~Stack()
    {
        delete[] ray;
        cout << "\nStack was destroyed\n";
    }

    void push(int val);
    void pop(void);
    int peek(void);
    bool isEmpty(void);
    bool isFull(void);
    void display(void);
};

bool Stack::isEmpty(void)
{
    return (top == -1);
}

bool Stack::isFull(void)
{
    return (top == cap - 1);
}

void Stack::push(int val)
{
    if (isFull())
    {
        cout << "Stack overflow! can not add " << val << endl;
        return;
    }

    ray[++top] = val;
    cout << val << " successfully pushed onto the stack....\n";
}

void Stack::pop(void)
{
    if (isEmpty())
    {
        cout << "Stack underflow! can not pop." << endl;
        return;
    }

    cout << ray[top] << " value successfully popped from stack" << endl;
    top--;
}

int Stack::peek(void)
{
    if (isEmpty())
    {
        cout << "Stack is empty; therefore, can not peek from stack.\n";
        return -1;
    }

    return (ray[top]);
}

void Stack::display(void)
{

    if (isEmpty())
    {
        cout << "Stack is empty, nothing to display...." << endl;
        return;
    }

    cout << "Displayig atck elements: \n";

    for (int m = 0; m <= top; m++)
    {
        cout << ray[top] << " ";
    }

    cout << endl;

}

int main(void)
{
    
    Stack s1(8);

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << "\nPeek value: " << s1.peek() << endl;


    s1.push(40);
    s1.push(50);
    s1.push(60);
    s1.push(70);
    s1.push(80);
    s1.push(90);

    cout << endl;

    cout << "\nPeek value: " << s1.peek() << endl;

    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();


    cout << "\nPeek value: " << s1.peek() << endl;

    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();

    cout << "\nPeek value: " << s1.peek() << endl;
    s1.pop();

    return 0;
}