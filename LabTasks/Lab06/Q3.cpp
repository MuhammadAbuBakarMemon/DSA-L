// 3. Using a stack implemented via linked list, check whether a given string is a palindrome.

#include <iostream>
#include <string>
using namespace std;

struct Node
{

    char data;
    Node* next;

        Node(char c)
        {
            data = c;
            next = NULL;
        }

};

class Stack 
{

    private:
        Node* top;
        // Node* tail;      totally unused

    public:

        Stack()
        {
            // tail = NULL;
            top = NULL;
        }

        ~Stack()
        {
            // delete tail;
            // delete top; just deleting top causes a memory leak 

            while (top != NULL)
            {
                Node* prev = top;
                top = top->next;
                delete prev;
            }
        }

        bool isEmpty()
        {
            return (top == NULL);
        }

        void push(char ch)
        {
            Node* n = new Node(ch);

            if (top == NULL)
            {
                top = n;
                return;
            }

            // inserting in reverse order
            n->next = top;
            top = n;

        }

        char pop()
        {
            if (isEmpty())
            {
                cout << "Stack underflow!!! Nothing to pop...." << endl;
                return 0;
            }

            char t = top->data;
            Node* prev = top;
            top = top->next;
            delete prev;
            return t;
        }

        char peek()
        {
            if (isEmpty())
            {
                cout << "Stack underflow!!! Nothing to pop...." << endl;
                return 0;
            }

            return top->data;
        }

};

bool isPalindrome(const string& st)
{

    Stack s1;

    size_t len = st.length();

    size_t mid = len / 2;
    
    for (int m = 0; m < mid; m++)
    {
        s1.push(st[m]);
    }

    int start = (len % 2 == 1) ? mid + 1 : mid;

    for (int m = start; m < len; m++)
    {
        if (s1.peek() != st[m])
        {
            return false;
        }
        else 
        {
            s1.pop();
        }
    }

    if (s1.isEmpty())
    {
        return true;
    }
}

int main(void)
{

    string str;
    cout << "Enter string: " << endl;
    cin >> str;

    if (isPalindrome(str))
    {
        cout << "Palindrome.\n";
    }
    else 
    {
        cout << "Not a palindrome.\n";
    }

    return 0;
}