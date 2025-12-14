// 1. Given two Binary Search Trees consisting of unique positive elements, the task is to
// check whether the two BSTs contain the same set of elements or not. The structure of
// the two given BSTs can be different.

#include <iostream>
#include <vector>

using namespace std;

struct Node 
{
    int data;
    Node* left;
    Node* right;
    
    Node(int m) : data(m), left(NULL), right(NULL) {}
};

void storeInOrder(Node* r, vector<int>& elements)
{
    if (r == NULL)
    {
        return;
    }

    storeInOrder(r->left, elements);
    elements.push_back(r->data);
    storeInOrder(r->right, elements);
}

bool sameSet(vector<int>& s1, vector<int>& s2)
{
    return (s1 == s2);
}

Node* insert(Node* r, int data)
{
    if (r == NULL)
    {
        return new Node(data);
    }

    if (data < r->data)
    {
        r->left = insert(r->left, data);
    }
    else if (data > r->data)
    {
        r->right = insert(r->right, data);
    }

    return r;
}

int main(void)
{
    Node* r1 = NULL;
    Node* r2 = NULL;

    r1 = insert(r1, 10);
    r1 = insert(r1, 20);
    r1 = insert(r1, 30);
    
    r2 = insert(r2, 20);
    r2 = insert(r2, 10);
    r2 = insert(r2, 30);

    vector<int> v1;
    vector<int> v2;

    storeInOrder(r1, v1);
    storeInOrder(r2, v2);

    if (sameSet(v1, v2))
    {
        cout << "Same\n";
    }
    else{
        cout << "Not Same\n";
    }

    return 0;
}