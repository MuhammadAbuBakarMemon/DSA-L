// Q2. Write a C++ program using a doubly linked list to manage a web browser’s history. The
// program should insert new websites visited, move backward to go to the previous page and move
// forward to revisit a page. Add function to search for a website in history.

#include <iostream>
#include <string>
using namespace std;

class Node 
{

    public: 
        Node* prev;
        string hist;
        Node* next;

        Node(const string& m) : prev(NULL), hist(m), next(nullptr) {}

};

class Doubly
{

    public:
        Node* head;
        Node* current;
        Node* tail;

        // okay so a dobly LL only needs a prev and next data member (at Node Level) to be called a doubly LL
        /* We use the current pointer at a class level in cases in which we want to store a music playlist or browsing history in a web browser
        This current pointer is pasrt of the List Logic
        we usw this as a support when we want to move forward/backward easily

        as we need to know the current music or browsing history we are at 
        for jsut the purposes of storing and trsversing the data structure we can do that manually as well, 
        we only use the current pointer based on logic if our program reequires us to remember a certain position
        
        */ 

        Doubly()
        {
            head = NULL;
            current = NULL;
            tail = NULL;
        }

        void addNWeb(const string& m)
        {

            Node* n = new Node(m);

            if (head == NULL)
            {
                head = tail = current = n;
                cout << "New website visited added to history." << endl;
                return;
            } 

            tail->next = n;
            n->prev = tail;
            tail = n;
            current = n;
            cout << "New website visited added to history." << endl;

        } 

        void movB()
        {
            if (current == NULL)
            {
                cout << "No current page loaded...." << endl;
                return;
            }

            if (current->prev == NULL)
            {
                cout << "Already at the first page, can not go back any further." << endl;
                return;
            }

            current = current->prev;
            cout << "Moved one page backward to: " << current->hist << endl;
        }

        void movF()
        {

            if (current == NULL)
            {
                cout << "No current Page loaded...." << endl;
                return;
            }

            if (current->next == NULL)
            {
                cout << "Already at the most recent page in the browsing history...." << endl;
                return;
            }

            current = current->next;
            cout << "Moved one step forward to: " << current->hist << endl;

        }

        void searchWeb(const string& m)
        {
            if (head == NULL)
            {
                cout << "No wesbsites in hostory to search from...." << endl;
                return;
            }

            Node* trav = head;

            while (trav != NULL)
            {
                if (trav->hist == m)
                {
                    cout << "Website found in history." << endl;
                    return;
                }

                trav = trav->next;
            }

            cout << "Website not found in history...." << endl;

        }

        void displayHist()
        {
            if (head == NULL)
            {
                cout << "No browsing history." << endl; 
                return;
            }

            cout << "\nBrowsing history: \n";
            
            Node* trav = head;

            while (trav != NULL)
            {
                if (trav == current)
                {
                    cout << "->" << trav->hist << "(current)" << endl;
                }
                else
                {
                    cout << " " << trav->hist << endl;
                }

                trav = trav->next;
            }
        }

};

int main(void)
{
    
    return 0;
}