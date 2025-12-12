// 1. Write a program to check for balanced parentheses { [ ( ) ] } using a stack

#include <iostream>
#include <string>
using namespace std;

class Stack 
{

    private:
        char* data; 
        int size;
        int top;

    public:

        Stack(int size)
        {
            this->size = size;
            data = new char[size];
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

        void push(char ch)
        {
            if (isFull())
            {
                cout << "Stack is Full...." << endl;
                return;
            }
            
            data[++top] = ch;
            cout << ch << " was inserted at the top of the stack...." << endl;

        }

        void pop()
        {
            if (isEmpty())
            {
                cout << "Stack is empty....\n";
                return;
            }

            cout << data[top] << " popped from the stack....\n";
            char temp = data[top];
            top--;

            // return temp;
        }

        char peek()
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

    string str;

    cout << "Enter the balanced parenthesis equation: " << endl;
    cin >> str;

    Stack s1(str.size());

    for (char c : str)
    {
        if (c == '[' || c == '{' || c == '(')
        {
            s1.push(c);
        }
        else if (c == ']' || c == '}' || c == ')')
        {

            // I missed the case where the string entered can be this ]}) (i.e starts withe the later paernthesis that is to come)
            // peeking on an emppty stack can cause undefined bahaviour

            if (s1.isEmpty())
            {
                cout << "Un-Balanced Parenthesis were entered...." << endl;
                return 0;
            }

            char comp = s1.peek();

            if (c == ')' && comp != '(' || c == '}' && comp != '{' || c == ']' && comp != '[')
            {
                cout << "Un-Balanced Parenthesis were entered...." << endl;
                return 0;
            }

            s1.pop();

        }
    }

    if (s1.isEmpty())
    {
        cout << "Balanced Parenthesis were entered...." << endl;
    }
    else 
    {
        cout << "Un-Balanced Parenthesis were entered...." << endl;
    }
    
    return 0;
}