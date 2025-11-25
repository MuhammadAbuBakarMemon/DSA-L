#include <iostream>
using namespace std;

class Node {
public:
    int s, e, h;
    Node *l, *r;
    Node(int a, int b) {
        s = a;
        e = b;
        h = 1;
        l = r = NULL;
    }
};

int gh(Node* z) {
    return z ? z->h : 0;
}

int bf(Node* z) {
    return gh(z->l) - gh(z->r);
}

Node* rr(Node* y) {
    Node* x = y->l;
    Node* t = x->r;
    x->r = y;
    y->l = t;
    y->h = max(gh(y->l), gh(y->r)) + 1;
    x->h = max(gh(x->l), gh(x->r)) + 1;
    return x;
}

Node* lr(Node* x) {
    Node* y = x->r;
    Node* t = y->l;
    y->l = x;
    x->r = t;
    x->h = max(gh(x->l), gh(x->r)) + 1;
    y->h = max(gh(y->l), gh(y->r)) + 1;
    return y;
}

bool chk(Node* z, int a, int b) {
    if (!z) return false;
    if (b <= z->s) return chk(z->l, a, b);
    else if (a >= z->e) return chk(z->r, a, b);
    return true;
}

Node* ins(Node* z, int a, int b) {
    if (!z) return new Node(a, b);
    if (b <= z->s) z->l = ins(z->l, a, b);
    else if (a >= z->e) z->r = ins(z->r, a, b);
    else return z;
    z->h = max(gh(z->l), gh(z->r)) + 1;
    int bal = bf(z);
    if (bal > 1 && a < z->l->s) return rr(z);
    if (bal < -1 && a > z->r->s) return lr(z);
    if (bal > 1 && a > z->l->s) {
        z->l = lr(z->l);
        return rr(z);
    }
    if (bal < -1 && a < z->r->s) {
        z->r = rr(z->r);
        return lr(z);
    }
    return z;
}

void disp(Node* z) {
    if (!z) return;
    disp(z->l);
    cout << "[" << z->s << "," << z->e << "] ";
    disp(z->r);
}

int main() {
    Node* r = NULL;
    int t[6][2] = { {9,11}, {11,12}, {10,13}, {13,15}, {16,18}, {15,16} };
    cout << "Office meeting schedule:\n";
    for (int x = 0; x < 6; x++) {
        int a = t[x][0], b = t[x][1];
        cout << "Meeting: " << a << "-" << b << " -> ";
        if (!chk(r, a, b)) {
            r = ins(r, a, b);
            cout << "added\n";
        } else cout << "conflict\n";
    }
    cout << "\nFinal confirmed meetings:\n";
    disp(r);
    cout << "\n";
}
