/*
 * MERGED LAB 08 CODE: Binary Trees and BST Operations
 * Based on National University of Computer and Emerging Sciences Lab Manual 08
 */

#include <iostream>
using namespace std;

// 1. Define the Node structure [cite: 39]
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor [cite: 43]
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// 2. Helper function to create a new node [cite: 52]
Node* createNode(int data) {
    return new Node(data);
}

// ---------------- TREE TRAVERSALS ----------------

// Preorder Traversal: Root -> Left -> Right [cite: 185]
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " "; // Visit Node
    preorder(root->left);      // Traverse Left
    preorder(root->right);     // Traverse Right
}

// In-order Traversal: Left -> Root -> Right [cite: 195]
// Note: In a BST, this prints values in sorted order [cite: 181]
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);       // Traverse Left
    cout << root->data << " "; // Visit Node
    inorder(root->right);      // Traverse Right
}

// Post-order Traversal: Left -> Right -> Root [cite: 198]
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);     // Traverse Left
    postorder(root->right);    // Traverse Right
    cout << root->data << " "; // Visit Node
}

// ---------------- BST OPERATIONS ----------------

// Search Operation [cite: 242]
Node* search(Node* root, int data) {
    // Base case: root is null or data is present at root
    if (root == NULL || root->data == data) {
        return root;
    }
    // Key is smaller than root's key -> Search Left
    if (data < root->data) {
        return search(root->left, data);
    }
    // Key is larger than root's key -> Search Right
    return search(root->right, data);
}

// Insert Operation [cite: 262]
Node* insert(Node* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(data);
    }
    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    // Return the (unchanged) node pointer
    return root;
}

// Helper function to find the minimum value node
// Required for Deletion Case 3 (finding inorder successor) 
Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Deletion Operation [cite: 299]
Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    // 1. Find the node to delete
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node found. Handle the 3 cases:

        // Case 1 & 2: Node with only one child or no child [cite: 312]
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root; // manual used free(), changed to delete for C++ safety
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node with two children [cite: 324]
        // Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);

        // Copy the inorder successor's data to this node [cite: 327]
        root->data = temp->data;

        // Delete the inorder successor [cite: 329]
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// ---------------- DRIVER CODE ----------------

int main() {
    Node* root = NULL;

    // Building the BST by inserting values
    // Using values similar to the manual's examples
    root = insert(root, 10);
    insert(root, 6);
    insert(root, 13);
    insert(root, 4);
    insert(root, 8);
    insert(root, 11);
    insert(root, 25);

    cout << "--- Tree Traversals ---" << endl;
    cout << "Inorder (Sorted): ";
    inorder(root); // Expected: 4 6 8 10 11 13 25
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    cout << "\n--- Search Operation ---" << endl;
    int searchVal = 8;
    Node* found = search(root, searchVal);
    if (found != NULL) {
        cout << "Element " << searchVal << " found in the BST." << endl;
    } else {
        cout << "Element " << searchVal << " not found." << endl;
    }

    cout << "\n--- Deletion Operation ---" << endl;
    cout << "Deleting node 6 (Node with two children: 4 and 8)..." << endl;
    root = deleteNode(root, 6);
    
    cout << "Inorder after deletion: ";
    inorder(root); // Expected: 4 8 10 11 13 25
    cout << endl;

    return 0;
}