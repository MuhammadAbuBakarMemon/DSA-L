#include <iostream>
using namespace std;


class Node 
{

    public:
        int data;
        Node* next;

        Node(int m)
        {
            data = m;
            next = NULL;
        }
};

class Singly
{

    private:
        Node* head;
        Node* tail;

    public:
        Singly()
        {
            head = NULL;
            tail = NULL;
        }

        void insertAtTail(int m)
        {

            Node* newNode = new Node(m);

            if (head == NULL && tail == NULL)
            {
                head = tail = newNode;
                cout << "Node was inserted in the empty list at the end////" << endl;
                return;
            }

            tail->next = newNode;
            tail = newNode;

            cout << "Node was inserted in the list at the end////" << endl;

            // This is a linked list that consists of a tail pointer 
            // Hence there is no need to take up a time complexity of O(n) to trasverse to the last element of the list
            // if some individual still sishes to use that approach then a commented out version for that can be found out below 
            // in order for lines 55 -  to function we need to comment out lines 44 - 47 since both of these set of lines
            // of code perform the same operation
            // Goodluck taking the long route, may Allah help you, In Sha Allah
            
            // Node* myTraverser = head;

            // while (myTraverser->next != NULL)
            // {
            //     myTraverser = myTraverser->next;
            // }

            // myTraverser->next = newNode;
            // tail = newNode;

            // cout << "Node was inserted in the list at the end////" << endl;

            // delete myTraverser;

        }

        void insertAtStart(int m)
        {

            Node* newNode = new Node(m);

            newNode->next = head;
            head = newNode;

        }

        // m is the value to insert and pos is the elements affter which we should be inserting the newNode

        void insertAfter(int pos, int val)
        {
            Node* myTraverser = head;

            for (int m = 0; m < pos && myTraverser != NULL; m++)
                myTraverser = myTraverser->next;

            if (myTraverser == NULL)
            {
                cout << "Position out of range////" << endl;
                return;
            }

            Node* newNode  = new Node(val);

            newNode->next = myTraverser->next;
            myTraverser->next = newNode;

            cout << "Node successfully inserted after position " << pos << ".\n";

            if (tail == myTraverser)
                tail = newNode;

        }

        bool serach(int valToSearch)
        {

            Node* myTraverser = head;

            while(myTraverser != NULL)
            {
                if (valToSearch == myTraverser->data)
                {
                    cout << "Value: " << valToSearch << " found in LinkedList////" << endl;

                    return true;
                }
            }

            cout << "Could not find value: " << valToSearch << " in LinkedList" << endl;
            return false;

        }

        void Display(void)
        {

            Node* myTraverser = head;

            while (myTraverser != NULL)
            {
                cout << myTraverser->data << "->";
                myTraverser = myTraverser->next;
            } 

            cout << endl;

        }

        void deleteAtEnd(void)
        {
            Node* myTraverser = head;

            if (head == NULL)
            {
                cout << "Linked List is empty, nothing to delete////" << endl;
                return;
            }

            if (head == tail)
            {
                // head = tail = NULL;
                // delete tail;
                // delete head;
                // are the above lines equivalent?

                /*
                No, they don't, because line 154 just changes the pointer head and tail to NULL, this line 154 is safe but it still faces 
                memory leaks if the 2 pointers are not deleted

                whilst line 155 and 156 free the dynamically allocated node pointed by these 2 memories
                but now the question arises that is executing these 2 lines correct?

                answer is No, the 2 point to the same memory and performing line 155 and 156 lead to double deletion which may cause unidentified behaviour
                
                please find the correct method from line number 171 - 172
                */

                delete head;
                head = tail = NULL;

                cout << "Deleted the only node from the list////" << endl;
                return;
            }

            while (myTraverser->next != tail)
            {
                myTraverser = myTraverser->next;
            }

            delete tail;
            
            cout << "Deleted the last node from the list////" << endl;

            tail = myTraverser;
            tail->next == NULL;

        }

        void deleteAtFront(void)
        {

            if (head == NULL)
            {
                cout << "Linked List is empty, nothing to delete////" << endl;
                return;
            }

            if (head == tail)
            {

                delete head;
                head = NULL;
                tail = NULL;

                cout << "Deleted the last node from the list////" << endl;
                return;

            }

            Node* myKeeper = head;
            head = head->next;

            delete myKeeper;
            cout << "Deleted the first node from the Linked List////" << endl;

        }

        void deleteAfter(int pos)
        {

            Node* myTraverser = head;
            Node* prevTraverser;

            int m = 0;

            while (myTraverser != NULL && m < pos)
            {
                prevTraverser = myTraverser;
                myTraverser = myTraverser->next;
                m++;
            }

            prevTraverser->next = myTraverser->next;
            delete myTraverser;
            cout << "Deleted the node at position " << pos << " from the list////" << endl;

            delete prevTraverser;

        }

}

// If someone is wondering why is every variable named after the letter 'm'; then it has no specific reason it's just that my 
// name starts from that letter Muhammad Abu Bakar Memon, so I just use it anywhere and everywhere
// If it had been in my hand I would have named every variabvle a single letter but then that code would only make sense to me, bad programming practice

int main (void)
{

    return 0;
}
