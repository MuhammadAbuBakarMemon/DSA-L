// Q1. Write a C++ program using a singly linked list to manage daily tasks. The program should add
// new tasks at the end of the list and insert urgent tasks at the beginning. In the end, perform the
// deletion of the tasks that are completed.

#include <iostream>
#include <string>
using namespace std;

class Node 
{

    public: 
        string Task;
        Node* next;

        Node (const string& m) : Task(m), next(NULL) {}

};

class Singly
{

    public:
        Node* head;

        Singly()
        {
            head = NULL;
        }

        void addTask(const string& Task)
        {

            Node* n = new Node(Task);

            if (head == NULL)
            {
                head = n;
                cout << "Inserted new task at the end of the list...." << endl;
                return;
            }

            Node* trav = head;

            while (trav && trav->next != NULL)
            {
                trav = trav->next;
            }

            trav->next = n;
            cout << "Inserted new task at the end of the list...." << endl;
            
        }

        void insertUrgentTask(const string& m)
        {
            Node* n = new Node(m);

            if (head == nullptr)
            {
                head = n;
                cout << "Inserted urgent task at the start of the list....\n";
                return; 
            }

            n->next = head;
            head = n;
            cout << "Inserted urgent task at the start of the list....\n";
        }

        void deleteTasks()
        {

            if (head == nullptr)
            {
                cout << "Linked List is empgty....\n";
                return;
            }

            Node* trav = head;

            // removing completed tasks from the head of the list
            while (head && head->Task == "Completed")
            {
                Node* toDel = head;
                head = head->next;
                delete toDel;
                cout << "Deletion operation performed....\n";
            }

            // This is commented out as it it an incorrect 
            // because according to this piece of code we only entered the loop and performed the delete operation only when the 
        // next node of trav has the task name as "Completed".

        // which should not be the case the procedure must delete any nodes in the list that have Tasks as Completed

            // while (trav->next && trav->next->Task == "Completed")
            // {
            //     Node* toDel = trav->next;
            //     trav->next = trav->next->next;
            //     delete toDel;
            //     cout << "Deletion operation performed....\n";
            // }

            while (trav &&  trav->next)
            {

                if (trav->next->Task == "Completed")
                {
                    Node* toDel = trav->next;
                    trav->next = trav->next->next;
                    delete toDel;
                    cout << "Deleteion operation performed....\n" << endl;
                }
                else
                {
                    trav = trav->next;
                }
            }

        }

        void display()
        {

            if (head == nullptr)
            {
                cout << "No Tasks in the Linked List to show/display....\n" << endl;
                return;
            }

            cout << "Current Tasks: " << endl;

            Node* trav = head;

            while (trav)
            {
                cout << "-" << trav->Task << endl;
                trav = trav->next;
            }
        }

};

int main(void)
{
    
    Singly l1;

    l1.insertUrgentTask("Khana Khao....");
    l1.addTask("Be a good human being,,,,");
    l1.addTask("Completed");
    l1.addTask("Get a rector's list this semester....");
    l1.addTask("Complete the comptia security+");
    l1.insertUrgentTask("Prepare for the Qabr....");
    l1.insertUrgentTask("Be good to my parents");
    l1.insertUrgentTask("Completed");

    cout << "Before...." << endl;
    l1.display();

    cout << endl;

    l1.deleteTasks();

    cout << "After deletion...." << endl;

    l1.display();

    return 0;
}