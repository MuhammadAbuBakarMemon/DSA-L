#include <iostream>
using namespace std;

class Node 
{

    public: 
        int data;
        Node* next; 

        Node(int val)
        {
            data = val;
            next = NULL;
        }

};

class LinkedList 
{

    public:
        Node* head;
        Node* tail;

        LinkedList()
        {
            head = NULL;
            tail = NULL;
        }

        void insertAtEnd(int data)
        {

            Node* n = new Node(data);

            if (head == NULL)
            {
                head = tail = n;
            }
            else
            {
                Node* temp = head;

                // if we would like to traverse the list and then insert the node the end
                // while (temp->next != NULL)
                // {
                //     temp = temp->next;
                // }
                // temp->next = n;
                // tail = n;
                // cout << "Successfully inserted node with the value [" << n->data << "] at the end of the list////" << endl;

                tail->next = n;
                tail = n;
                cout << "Successfully inserted node with the value [" << n->data << "] at the end of the list////" << endl;
                return;
            }
            
        }

        void insertAtStart(int data)
        {

            Node* n = new Node(data);

            if (head == NULL)
            {
                head = tail = n;
            }
            else 
            {
                n->next = head;
                head = n;
                cout << "Successfully inserted node with the value [" << n->data << "] at the start of the list////" << endl;
                return;
            }

        }

        void insertAfter(int pos, int data)
        {
            if (pos == 0)
            {
                insertAtStart(data);
                return;
            }

            Node* n = new Node(data);
            Node* curr = head;

            for (int m = 0; m < pos && curr != NULL; m++)
            {
                curr = curr->next;
            }

            if (curr == NULL)
            {
                delete n;
                cout << "Position out of bounds////" << endl;
                return;
            }

            n->next = curr->next;
            curr->next = n;
            
            if (curr == tail)
            {
                tail = n;
            }

            cout << "Inserted value " << data << " after index " << pos << ".\n";

        }

        void display(void)
        {
            Node* temp = head;

            while (temp != NULL)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "nullptr" << endl;
        }

        bool search(int key)
        {
            int nodeTraverser = 0;
            Node* trav = head;

            while (trav != nullptr)
            {
                if (trav->data == key)
                {
                    cout << "An instance of value [" << key << "] was found in Linked List at index number [" << nodeTraverser << "]////" << endl;
                    return true;
                }

                trav = trav->next;
                nodeTraverser++;
            }

            cout << "No instance of value [" << key << "] was found in Linked List////" << endl;
            return false;
        }

        void deleteFromEnd(void)
        {
            
            if (head == NULL)
            {
                cout << "Linked List is empty////" << endl;
                return;
            }

            if (head == tail)
            {
                cout << "Node with value of [" << head->data << "] deleted from the end of the Linked List////";
                delete head;
                head = tail = NULL;
                return;
            }

            Node* trav = head;

            while (trav->next != tail)
            {
                trav = trav->next;
            }

            cout << "Node with value of [" << tail->data << "] deleted from the end of the Linked List////" << endl;
            delete tail;
            tail = trav;
            tail->next = nullptr;
        }

        void deleteFromStart(void)
        {
            if (head == nullptr)
            {
                cout << "Linked List is empty////" << endl;
                return;
            }

            if (head == tail)
            {
                cout << "Node with value of [" << head->data << "] successfully deleted from the startof the Linked List////" << endl;
                delete head;
                head = tail = NULL;
                return;
            }

            Node* temp = head;
            head = head->next;
            cout << "Node with value of [" << temp->data << "] successfully deleted from the start of the linked list////" << endl;
            delete temp;

        }

        void deleteAfter(int pos)
        {
            if (pos == 0)
            {
                deleteFromStart();
                return;
            }

            Node* curr = head;

            for (int m = 0 ; m < pos && curr != NULL; m++)
            {
                curr = curr->next;
            }

            if (curr == nullptr || curr->next == NULL)
            {
                cout << "Position out of bounds accessing////" << endl;
                return;
            }

            Node* toDelete = curr->next;
            curr->next = toDelete->next;

            // we need to check if waht we are delteing just coincidently happens to be the tail pointer then we must also ensure that we are 
            // appropriately updating the tail pointer

            if (toDelete == tail)
            {
                tail = curr;
            }

            cout << "Node with value of [" << toDelete->data << "] successfully deleted from the Linked List////" << endl;
            delete toDelete;
        }

};

int main(void)
{
    
    LinkedList list;

    list.insertAtEnd(25);
    list.insertAtStart(1);
    list.insertAtEnd(50);
    list.insertAfter(1, 40);
    list.display();

    cout << std::endl;

    list.search(50);
    list.insertAtEnd(100);

    cout << "\n";

    list.deleteAfter(1);
    list.display();

    cout << endl;

    list.deleteFromEnd();
    list.deleteFromStart();
    list.display();

    return 0;
}