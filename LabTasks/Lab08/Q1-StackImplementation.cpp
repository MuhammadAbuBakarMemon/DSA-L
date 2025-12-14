#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;  // FIXED: Changed Node* to TreeNode*
    TreeNode* right; // FIXED: Changed Node* to TreeNode*
    
    TreeNode(int v) : data(v), left(NULL), right(NULL) {}
};

bool sameSet(TreeNode* r1, TreeNode* r2)
{
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;

    while(true)
    {
        while (r1)
        {
            s1.push(r1);
            r1 = r1->left;
        }

        while (r2)
        {
            s2.push(r2);
            r2 = r2->left;
        }

        if (s1.empty() && s2.empty())
        {
            return true;
        }

        if (s1.empty() || s2.empty())
        {
            return false;
        }

        // FIXED: C++ pop() returns void. Use top() then pop().
        r1 = s1.top(); 
        s1.pop();
        
        r2 = s2.top();
        s2.pop();

        // FIXED: Used 'data' because that is what you defined in the struct
        if (r1->data != r2->data)
        {
            return false;
        }

        r1 = r1->right;
        r2 = r2->right;
    }
}

TreeNode* insert(TreeNode* node, int key) {
    if (node == NULL) return new TreeNode(key);
    
    // FIXED: Used 'data' instead of 'val'
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}

int main() {
    // BST 1: 10, 5, 15
    TreeNode* root1 = NULL;
    root1 = insert(root1, 10);
    root1 = insert(root1, 5);
    root1 = insert(root1, 15);

    // BST 2: Different structure, same elements
    TreeNode* root2 = NULL;
    root2 = insert(root2, 5);
    root2 = insert(root2, 10);
    root2 = insert(root2, 15);

    // BST 3: Different elements (10, 6, 15)
    TreeNode* root3 = NULL;
    root3 = insert(root3, 10);
    root3 = insert(root3, 6); 
    root3 = insert(root3, 15);

    // FIXED: Function name is 'sameSet', not 'checkSameSet'
    if (sameSet(root1, root2))
        cout << "Test 1: Same set." << endl;
    else
        cout << "Test 1: Different set." << endl;

    if (sameSet(root1, root3))
        cout << "Test 2: Same set." << endl;
    else
        cout << "Test 2: Different set." << endl;

    return 0;
}