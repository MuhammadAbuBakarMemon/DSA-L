#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* right;
    Node* left;

    Node(int m)
    {
        data = m;
        left = right = NULL;
    }
};

Node* createNode(int value)
{
    return new Node(value);
}

void preorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->left);
    cout << root->data << " ";
}

Node* search(Node* root, int valToSearch)
{
    if (root == NULL || root->data == valToSearch)
    {
        return root;
    }

    if (valToSearch < root->data)
    {
        return search(root->left, valToSearch);
    }
    else 
    {
        return search(root->right, valToSearch);
    }

}

Node* insert(Node* root, int valToAdd)
{
    if (root == NULL)
    {
        return createNode(valToAdd);
    }

    if (valToAdd < root->data)
    {
        root->left = insert(root->left, valToAdd);
    }
    else if (valToAdd > root->data)
    {
        root->right = insert(root->right, valToAdd);
    }

    return root;
}

Node* findMin(Node* root)
{
    while (root && root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

Node* deleteNode(Node* root, int valToDelete)
{
    if (root == NULL)
    {
        return root;
    }

    if (valToDelete < root->data)
    {
        root->left = deleteNode(root->left, valToDelete);
    }
    else if (valToDelete > root->data)
    {
        root->right = deleteNode(root->right, valToDelete);
    }
    else 
    {
        if (root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);

    }

    return root;
}

int main(void)
{
    
    return 0;
}