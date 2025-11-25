#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v) {
        data = v;
        next = nullptr;
    }
};

class Singly {
public:
    Node* head;
    Singly() {
        head = nullptr;
    }

    void insert(int v) {
        Node* n = new Node(v);
        n->next = head;
        head = n;
    }

    void printReverse(Node* p) {
        if (p == nullptr) return;
        printReverse(p->next);
        cout << p->data << " ";
    }
};

int main() {
    Singly s;
    s.insert(5);
    s.insert(4);
    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.printReverse(s.head);
}
