#include <iostream>
using namespace std;

struct Node 
{
    int salary;
    Node* next;
};

void insertEnd(Node*& head, int value) 
{
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) 
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node* head) 
{
    Node* temp = head;
    while (temp != nullptr) 
    {
        cout << temp->salary << " ";
        temp = temp->next;
    }
    cout << endl;
}

void selectionSort(Node* head) 
{
    for (Node* x = head; x != nullptr; x = x->next) 
    {
        Node* minNode = x;
        for (Node* y = x->next; y != nullptr; y = y->next) 
        {
            if (y->salary < minNode->salary) 
            {
                minNode = y;
            }
        }
        if (minNode != x) 
        {
            int temp        = x->salary;
            x->salary       = minNode->salary;
            minNode->salary = temp;
        }
    }
}

int main() 
{
    int n;
    cout << "How many employees? ";   
    cin >> n;
    
    Node* head = nullptr;
    
    cout << "Enter salaries of " << n << " employees:" << endl; 
    for (int x = 0; x < n; x++) 
    {
        int s;
        cout << "Salary of empoyee " << x + 1 << ": "; 
        cin >> s;
        insertEnd(head, s);
    }
    
    cout << "\nSalaries befor sorting: "; 

    printList(head);
    
    selectionSort(head);
    
    cout << "Salaries after sortng:  "; 
    printList(head);
    
    return 0;
}
