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

    // via using previous pointer

    // void insertAfter(int pos, int val)
    // {
    //     Node *n = new Node(val);

    //     Node * curr = head;
    //     Node * prev;

    //     for (int m = 0; m < pos; m++)
    //     {
    //         prev = curr;
    //         curr = curr->next;
    //     }

    //     prev->next = n;
    //     n->next = curr;

    //     cout << "Inserted value " << val << " at position " << pos << endl;

    // }

    // without previous pointer

    void insertAfter(int pos, int val)
    {

        if (pos == 0)
        {
            insertAtStart(val);
            return;
        }

        Node * n = new Node(val);
        Node * curr = head;

        for (int m = 0; m < pos && curr != nullptr; m++)
        {
            curr = curr->next;
        }

        if (curr == nullptr)
        {
            cout << "Position out of range...." << endl;
            delete n;
            return;
        }

        n->next = curr->next;
        curr->next = n;

        if (curr == tail)
        {
            tail = n;
        }

        cout << "Inserted value " << val << " after index " << pos << endl;

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

    void deleteFromEnd(void)
    {

        if (head == nullptr)
        {
            cout << "Linked List is emphty...." << endl;
            return;
        }

        // only one node in Linked List 
        
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            cout << "Deleted from the end (the only node) of the Linked List...." << endl;
        } 

        Node * temp = head;

        while(temp->next != tail)
        {
            temp = temp->next;
        }

        delete tail;
        cout << "Deleted from the end of the Linked List...." << endl;
        tail = temp;
        // if we do not write the statement below this comment than our new tail is still pointing to the old tail (which we just deleted....) 
        tail->next = nullptr;
        return;
        
    }

    void deleteFromStart(void)
    {
        if (head == nullptr)
        {
            cout << "List is emphty...." << endl;
            return;
        }

        if (head == tail)
        {
            delete head;
            cout << "Deleted from the start (the only node) of the Linked List...." << endl;
            head =  tail = nullptr;
            return;
        }

        Node * temp = head;

        head = head->next;
        delete temp;

        cout << "Deleted from the start of the Linked List...." << endl;
    }

    void deleteAfter(int pos)
    {
        if (pos == 0)
        {
            deleteFromStart();
            return;
        }

        Node * curr = head;

        for (int m = 0; m < pos && curr != nullptr; m++)
        {
            curr = curr->next;
        }

        if (curr == nullptr || curr->next == nullptr)
        {
            cout << "No node exists after the position...." << endl;
            delete curr;
            return;
        }

        Node * toDel = curr->next;
        curr->next = toDel->next;

        if (toDel == tail)
        {
            tail = curr;
        }

        delete toDel;
        cout << "Node was deleted from the position " << pos << " of the Linked List...." << endl;

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

    list.insertAfter(1, 8);
    list.insertAfter(2, 9);

    list.deleteFromEnd();
    list.deleteFromStart();
    list.deleteAfter(3);

    list.search(8);

    list.disp();
    
    return 0;
}