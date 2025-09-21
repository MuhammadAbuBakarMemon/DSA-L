#include <iostream>
using namespace std;

class Node
{
    public:

    int data;
    Node * next;

    Node(int v)
    {
        data = v;
        next = nullptr;
    }
};

class Singly 
{

    public:
    Node* head;
    Node* tail;

    Singly()
    {
        head = nullptr;
        tail = nullptr;
    }

    // inserting at end -> Append

    void insertAtTail(int val)
    {
        Node* n = new Node(val);

        if (head == nullptr)
        {
            head = tail = n;
        }
        else 
        {

            tail->next = n;
            tail = n;

        }

        // The purpose of having a tail pointer is to avoid traversing when inserting at the end....

        // Node* temp = head;
        // while (temp->next != nullptr)
        // {
        //     temp = temp->next;
        // }
        // temp->next = n;
        // tail = n;

        cout << "Inserted value " << val << " at tail" << "...." << endl;

    }

    void insertAtStart(int val)
    {
        Node* n = new Node(val);

        if (head == nullptr)
        {
            head = tail = n;
        }
        else
        {
            n->next = head;
            head = n;
        }

        cout << "Inserted value " << val << " at head...." << endl;
    }

    void disp(void)
    {

        Node * temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "nullptr" << endl;
    }

    void insertAfter(int pos, int val)
    {
        Node *n = new Node(val);

        Node * curr = head;
        Node * prev;

        for (int m = 0; m < pos; m++)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = n;
        n->next = curr;

        cout << "Inserted value " << val << " at position " << pos << endl;

    }

    bool search(int key)
    {
        Node * temp = head;

        int nodetracker = 0;

        while (temp != nullptr)
        {
            nodetracker++;

            if (key == temp->data)
            {
                cout << "Value " << key << " found at Node number " << nodetracker << " in the Linked List...." << endl;
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    void deleteFromEnd()
    {
        
    }

};



int main(void)
{

    Singly list;

    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);

    list.insertAtStart(5);
    list.insertAtStart(1);

    list.insertAfter(2, 8);
    list.insertAfter(3, 9);

    list.disp();

    list.search(8);
    
    return 0;
}