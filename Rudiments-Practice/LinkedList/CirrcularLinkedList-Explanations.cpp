#include <iostream>

using namespace std;

// 1. Standard Node Structure
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// 2. Circular Linked List Class
class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularLinkedList() : head(nullptr) {}

    // Destructor to free memory
    ~CircularLinkedList() {
        if (!head) return;

        Node* current = head;
        Node* nextNode = nullptr;

        // Loop until we circle back to head
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);

        head = nullptr;
    }

    // --- Helper to check if empty ---
    bool isEmpty() {
        return head == nullptr;
    }

    // --- Insertion Functions ---

    // Insert at the beginning
    void insertAtHead(int val) {
        Node* newNode = new Node(val);

        if (isEmpty()) {
            head = newNode;
            newNode->next = head; // Points to itself
        } else {
            Node* temp = head;
            // Traverse to the last node
            while (temp->next != head) {
                temp = temp->next;
            }
            // Last node points to new node
            temp->next = newNode;
            // New node points to current head
            newNode->next = head;
            // Update head pointer
            head = newNode;
        }
    }

    // Insert at the end
    void insertAtTail(int val) {
        Node* newNode = new Node(val);

        if (isEmpty()) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // New tail points back to head
        }
    }

    // Insert at specific position (1-based index)
    void insertAtPosition(int pos, int val) {
        if (pos <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 1) {
            insertAtHead(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        int count = 1;

        // Move to the node before the insertion point
        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        // Connect new node
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // --- Deletion Functions ---

    void deleteHead() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->next == head) { // Only one node in list
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            Node* last = head;

            // Find the last node
            while (last->next != head) {
                last = last->next;
            }

            // Move head forward
            head = head->next;
            // Update last node to point to new head
            last->next = head;
            delete temp;
        }
    }

    void deleteTail() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->next == head) { // Only one node
            delete head;
            head = nullptr;
        } else {
            Node* current = head;
            Node* prev = nullptr;

            // Stop at the last node
            while (current->next != head) {
                prev = current;
                current = current->next;
            }

            prev->next = head; // Second to last node becomes tail
            delete current;
        }
    }

    void deleteByValue(int val) {
        if (isEmpty()) return;

        // If head holds the value
        if (head->data == val) {
            deleteHead();
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        do {
            if (current->data == val) {
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);

        cout << "Value " << val << " not found." << endl;
    }

    // --- Utilities ---

    bool search(int val) {
        if (isEmpty()) return false;
        Node* temp = head;
        do {
            if (temp->data == val) return true;
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    // Reverse the circular links
    void reverse() {
        if (isEmpty() || head->next == head) return;

        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;
        Node* lastNode = head; // The old head becomes the new last node

        // Standard reversal logic
        do {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        } while (current != head);

        // 'prev' is now the new head. 
        // We must update the old head (now tail) to point to the new head.
        head = prev;
        lastNode->next = head; 
    }

    void display() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        
        //  could be useful here conceptually
        
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(HEAD)" << endl;
    }
};

// --- Driver Code ---
int main() {
    CircularLinkedList cll;

    cll.insertAtTail(10);
    cll.insertAtTail(20);
    cll.insertAtTail(30);
    cout << "Initial list: ";
    cll.display();

    cll.insertAtHead(5);
    cout << "After inserting 5 at Head: ";
    cll.display();

    cll.deleteHead();
    cout << "After deleting Head: ";
    cll.display();

    cll.reverse();
    cout << "After Reversing: ";
    cll.display();

    return 0;
}