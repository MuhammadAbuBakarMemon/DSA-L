#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int m) : data(m), next(NULL) {}
};

class CirrcularLinkedList 
{
    
    private:
        Node* head;

    public:     
        CirrcularLinkedList()
        {
            head = NULL;
        }

        ~CirrcularLinkedList()
        {
            
            if (!head)
            {
                return;
            }

            Node* trav = head;
            Node* nextNode = NULL;

            do
            {
                nextNode = trav->next;
                delete trav;
                trav = nextNode;
            } while(trav != NULL);

            head = NULL;
        }

        bool isEmpty()
        {
            return (head == NULL);
        }

        void insertAtHead(int val)
        {

            Node* n = new Node(val);

            if (isEmpty())
            {
                head = n;
                n->next = head;    
                return;
            }

            Node* trav = head;
            while(trav->next != head)
            {
                trav = trav->next;
            }

            trav->next = n;
            n->next = head;
            head = n;
        }

        void insertAtTail(int val)
        {
            Node* n = new Node(val);

            if(isEmpty())
            {
                head = n;
                n->next = head;
                return;
            }

            Node* trav = head;
            while(trav->next != head)
            {
                trav = trav->next;
            }

            trav->next = n;
            n->next = head;
        }

        // 1-based index 
        void insertAtPosition(int val, int pos)
        {
            Node* n = new Node(val);

            if (pos <= 0)
            {
                cout << "Invalid Position!!!" << endl;
                return;
            }

            if (pos == 1)
            {
                insertAtHead(val);
                return;
            }

            int count = 1;
            Node* trav = head;

            while (count < pos - 1 && trav->next != head)
            {
                trav = trav->next;
                count++;
            }

            n->next = trav->next;
            trav->next = n;

        }

        void deleteAtHead()
        {
            if (isEmpty())
            {
                cout << "List is empty.\n";
                return;
            }

            if (head->next == head)
            {
                delete head;
                head = NULL;
                return;
            }

            Node* trav = head;
            Node* prev = head;

            while(prev->next != head)
            {
                prev = prev->next;
            }

            head = head->next;
            prev->next = head;
            delete trav;
        }

        void deleteAtTail()
        {
            if (isEmpty())
            {
                return;
            }

            if (head->next == head)
            {
                delete head;
                head = NULL;
                return;
            }

            Node* trav = head;
            Node* prev = NULL;

            while (trav->next != head)
            {
                prev = trav;
                trav = trav->next;
            }

            prev->next = head;
            delete trav;
        }

        void deleteByValue(int val)
        {
            if (isEmpty())
            {
                return;
            }

            if (head->data == val)
            {
                deleteAtHead();
                return;
            }

            Node* trav = head;
            Node* prev = NULL;

            do 
            {
                if(trav->data == val)
                {
                    prev->next = trav->next;
                    delete trav;
                    return;
                }
                prev = trav;
                trav = trav->next;
            } while(trav !=head);

            cout << "Value: " << val << " not found.\n" << endl;
        }

        bool seaech(int val)
        {
            if (isEmpty())
            {
                return false;
            }

            Node* trav = head;
            do 
            {
                if (trav->data == val)
                {
                    return true;
                }

                trav = trav->next 
            } while(trav != NULL);

            return false;
        }

        void reverse()
        {
            if (isEmpty() || head->next == head)
            {
                return;
            }

            Node* current = head;
            Node* prev = NULL;
            Node* nxt = NULL;
            Node* lastNode = head;

            do 
            {
                nxt = current->next;
                current->next = prev;
                prev = curr;
                curr = nxt;
            } while(current != NULL);

            head = prev;
            lastNode->next = head;
        }

        void display()
        {
            if (isEmpty())
            {
                cout << "Empty List.\n";
                return;
            }
            
            Node* trav = head;

            do 
            {
                cout << trav->data << "->";
                trav = trav->next;
            } while (trav != NULL)
            cout << "(HEAD)" << endl;
        }

};

int main(void)
{
    
    return 0;
}