// 2. Create a program that evaluates a postfix arithmetic expression using a stack — like how
// compilers compute mathematical operations. Given a postfix expression (e.g.
// "23*54*+9-"), evaluate and output the result

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Stack 
{

    private:
        int* data; 
        int size;
        int top;

    public:

        Stack(int size)
        {
            this->size = size;
            data = new int[size];
            top = -1;
        }

        ~Stack()
        {
            delete[] data;
        }

        bool isEmpty()
        {
            return (top == -1);
        }

        bool isFull()
        {
            return (top == size - 1); 
        }

        void push(int ch)
        {
            if (isFull())
            {
                cout << "Stack is Full...." << endl;
                return;
            }
            
            data[++top] = ch;
            cout << ch << " was inserted at the top of the stack...." << endl;

        }

        int pop()
        {
            if (isEmpty())
            {
                cout << "Stack is empty....\n";
                return -1;
            }

            cout << data[top] << " popped from the stack....\n";
            int temp = data[top];
            top--;

            return temp;
        }

        int peek()
        {
            if (isEmpty())
            {
                cout << "Stack is empty....\n";
                return -1;
            }

            return data[top];
        }

};

int main(void)
{

    string exp;
    
    cout << "Enter Mathematical Expression: " << endl;
    cin >> exp;

    Stack s1(exp.length());

    for (char c : exp)
    {
        if (c >= '0' && c <= '9')
        {
            s1.push(c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c  == '^')
        {
            int c2 = s1.pop();
            int c1 = s1.pop();

            if (c == '+')
            {
                s1.push(c1 + c2);
                continue;
            }
            else if (c == '-')
            {
                s1.push(c1 - c2);
                continue;
            }
            else if (c == '*')
            {
                s1.push(c1 * c2);
                continue;
            }
            else if (c == '/')
            {
                s1.push(c1 / c2);
                continue;
            }
            else
            {
                s1.push(pow(c1, c2));
            }

        }
    }

    cout << "Answer: " << s1.peek() << endl;

    return 0;
}