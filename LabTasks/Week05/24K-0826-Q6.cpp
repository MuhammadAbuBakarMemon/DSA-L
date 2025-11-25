#include <iostream>
using namespace std;

class Node {
public:
    long long data;
    Node* next;
    Node(long long v) {
        data = v;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }

    void insert(long long v) {
        Node* n = new Node(v);
        if (!head) head = n;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = n;
        }
    }

    int getMaxDigits() {
        Node* temp = head;
        long long mx = 0;
        while (temp) {
            if (temp->data > mx) mx = temp->data;
            temp = temp->next;
        }
        int digits = 0;
        while (mx) {
            digits++;
            mx /= 10;
        }
        return digits;
    }

    void radixSort() {
        int maxDigits = getMaxDigits();
        long long exp = 1;

        for (int i = 0; i < maxDigits; i++) {
            // Create 10 buckets
            Node* bucketHead[10] = {nullptr};
            Node* bucketTail[10] = {nullptr};

            Node* temp = head;
            while (temp) {
                int digit = (temp->data / exp) % 10;
                Node* nextNode = temp->next;
                temp->next = nullptr;

                if (!bucketHead[digit]) {
                    bucketHead[digit] = temp;
                    bucketTail[digit] = temp;
                } else {
                    bucketTail[digit]->next = temp;
                    bucketTail[digit] = temp;
                }
                temp = nextNode;
            }

            // Rebuild list from buckets
            head = nullptr;
            Node* tail = nullptr;
            for (int d = 0; d < 10; d++) {
                if (bucketHead[d]) {
                    if (!head) {
                        head = bucketHead[d];
                        tail = bucketTail[d];
                    } else {
                        tail->next = bucketHead[d];
                        tail = bucketTail[d];
                    }
                }
            }

            exp *= 10;
        }
    }

    bool search(long long val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insert(2023012456);
    list.insert(2023012101);
    list.insert(2023012987);
    list.insert(2023012005);
    list.insert(2023012609);

    cout << "Before Sorting:" << endl;
    list.print();

    list.radixSort();

    cout << "After Radix Sort:" << endl;
    list.print();

    long long key;
    cout << "Enter registration number to search: ";
    cin >> key;
    if (list.search(key)) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    return 0;
}
