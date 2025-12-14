// 2. A platform tracks user based on their engagement score, which changes daily as they
// complete quizzes or watch lectures. Design a BST that stores user profiles and their
// engagement scores. It can efficiently find the most/least active learners. It should be able
// to supports deletion when users deactivate their accounts. Then use traversal to produce
// a “leaderboard” of engagement.

#include <iostream>
using namespace std;

struct Node
{
    int uid;
    int sc;
    Node* left;
    Node* right;

    Node(int id, int score) : uid(id), sc(score), left(NULL), right(NULL) {}
};

class EngagementBST
{
    private:
        Node* root;

        Node* insert(Node* r, int uid, int sc)
        {
            if (r == NULL)
            {
                return new Node(uid, sc);
            }

            if (sc < r->sc)
            {
                r->left = insert(r->left, uid, sc);
            }
            else if (sc > r->sc)
            {
                r->right = insert(r->right, uid, sc);
            }

            return r;

        }

        Node* findMin(Node* r)
        {
            Node* trav = r;

            while (trav && trav->left != NULL)
            {
                trav = trav->left;
            }

            return trav;
        }

        Node* deleteUser(Node* r, int uid, int sc)
        {

            if (r == NULL)
            {
                return r;
            }

            if (sc < r->sc)
            {
                r->left = deleteUser(r->left, uid, sc);
            } 
            else if (sc > r->sc)
            {
                r->right = deleteUser(r->right, uid, sc);
            }
            else 
            {
                if (r->uid != uid)
                {
                    r->right = deleteUser(r->right, uid, sc);
                }
                else
                {

                    if (r->right == NULL)
                    {
                        Node* temp = r->left;
                        delete r;
                        return temp;
                    }
                    else if (r->left == NULL)
                    {
                        Node* temp = r->left;
                        delete r;
                        return temp;
                    }
                   
                    Node* temp = findMin(r->right);

                    r->sc = temp->sc;
                    r->uid = temp->uid;

                    r->right = deleteUser(r->right, temp->uid, temp->sc);
                }

            }

        }

        void printLeaderboard(Node* r)
        {
            if (r == NULL)
            {
                return;
            }

            printLeaderboard(r->right);
            cout << "User Id: " << r->uid << " | Score: " << r->sc << endl;
            printLeaderboard(r->left);
        }
};

int main(void)
{
    
    return 0;
}