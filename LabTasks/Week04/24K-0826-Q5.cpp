#include <iostream>
using namespace std;

struct Node 
{
    int salary;
    Node* next;
};

void insertEnd(Node*& head, int value) 
{
    Node* newNode = new Node;
    newNode->salary = value;
    newNode->next = nullptr;

    if(head == nullptr) 
    {
        head = newNode;
    } 
    else 
    {
        Node* x = head;
        while(x->next != nullptr) 
        {
            x = x->next;
        }
        x->next = newNode;
    }
}

void printList(Node* head) 
{
    Node* y = head;
    while(y != nullptr) 
    {
        cout << y->salary << " ";
        y = y->next;
    }
    cout << endl;
}

void selectionSort(Node* head) 
{
    for(Node* x = head; x != nullptr; x = x->next) 
    {
        Node* maxNode = x;
        for(Node* y = x->next; y != nullptr; y = y->next) 
        {
            if(y->salary > maxNode->salary) 
            {
                maxNode = y;
            }
        }
        int temp = x->salary;
        x->salary = maxNode->salary;
        maxNode->salary = temp;
    }
}

int main() 
{
    Node* head = nullptr;
    int n;

    cout << "How many employee salaries do you want to enter? ";
    cin >> n;

    cout << endl << "Please enter the salaries:\n";
    for(int x = 0; x < n; x++) 
    {
        int s;
        cout << "Salary for employee #" << x + 1 << ": ";
        cin >> s;
        insertEnd(head, s);
    }

    cout << endl << "Salaries before sorting:\n";
    printList(head);

    selectionSort(head);

    cout << "\nSalaries after sorting (highest first):\n";
    printList(head);

    return 0;
}
