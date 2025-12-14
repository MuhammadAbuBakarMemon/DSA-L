// Joshephus Problem

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    // Node(int val)
    // {
    //     data = val;
    //     next = NULL;
    // }
};

Node* createNode(int val)
{
    Node* n = new Node;
    n->data = val; 
    n->next = NULL;
    return n;
}

void solveJosephus(int N, int K)
{
    Node* head = createNode(1);
    Node* trav = head;

    for (int m = 2; m <= N; m++)
    {
        trav->next  = createNode(m);
        trav = trav->next;
    }

    trav->next = head;

    Node* ptr1 = head;
    Node* ptr2 = head;

    while (ptr2->next != NULL)
    {
        ptr2 = ptr2->next;
    }

    while (ptr1->next != ptr1)
    {

        int count = 0;

        while(count < K)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
            count++;
        }

        cout << "Player: " << data << " elinminated.\n";
        ptr2->next = ptr1->next;

        delete ptr1;
        ptr1 = ptr2->next;
        
    }

    cout << "The Winner is player: " << ptr1->data << ".\n";
}

int main(void)
{
    
    return 0;
}