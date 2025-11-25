#include <iostream>
using namespace std;

class Node {
public:
    int id, l, h;
    Node *a, *b;
    Node(int x, int y) {
        id = x; l = y; h = 1; a = b = NULL;
    }
};

int gh(Node* z) {
    return z ? z->h : 0;
}

int bf(Node* z) {
    return gh(z->a) - gh(z->b);
}

Node* rr(Node* y) {
    Node* x = y->a;
    Node* t = x->b;
    x->b = y;
    y->a = t;
    y->h = max(gh(y->a), gh(y->b)) + 1;
    x->h = max(gh(x->a), gh(x->b)) + 1;
    return x;
}

Node* lr(Node* x) {
    Node* y = x->b;
    Node* t = y->a;
    y->a = x;
    x->b = t;
    x->h = max(gh(x->a), gh(x->b)) + 1;
    y->h = max(gh(y->a), gh(y->b)) + 1;
    return y;
}

Node* ins(Node* z, int id, int l) {
    if (!z) return new Node(id, l);
    if (l < z->l || (l == z->l && id < z->id)) z->a = ins(z->a, id, l);
    else z->b = ins(z->b, id, l);
    z->h = max(gh(z->a), gh(z->b)) + 1;
    int bal = bf(z);
    if (bal > 1 && l < z->a->l) return rr(z);
    if (bal < -1 && l > z->b->l) return lr(z);
    if (bal > 1 && l > z->a->l) {
        z->a = lr(z->a);
        return rr(z);
    }
    if (bal < -1 && l < z->b->l) {
        z->b = rr(z->b);
        return lr(z);
    }
    return z;
}

Node* mn(Node* z) {
    while (z->a) z = z->a;
    return z;
}

Node* del(Node* z, int id, int l) {
    if (!z) return z;
    if (l < z->l || (l == z->l && id < z->id)) z->a = del(z->a, id, l);
    else if (l > z->l || (l == z->l && id > z->id)) z->b = del(z->b, id, l);
    else {
        if (!z->a || !z->b) {
            Node* t = z->a ? z->a : z->b;
            delete z;
            return t;
        } else {
            Node* t = mn(z->b);
            z->id = t->id;
            z->l = t->l;
            z->b = del(z->b, t->id, t->l);
        }
    }
    z->h = max(gh(z->a), gh(z->b)) + 1;
    int bal = bf(z);
    if (bal > 1 && bf(z->a) >= 0) return rr(z);
    if (bal > 1 && bf(z->a) < 0) {
        z->a = lr(z->a);
        return rr(z);
    }
    if (bal < -1 && bf(z->b) <= 0) return lr(z);
    if (bal < -1 && bf(z->b) > 0) {
        z->b = rr(z->b);
        return lr(z);
    }
    return z;
}

Node* least(Node* z) {
    return z ? mn(z) : NULL;
}

int main() {
    Node* r = NULL;
    int n = 5;
    int a[5][2] = { {1,30}, {2,40}, {3,20}, {4,50}, {5,25} };
    cout << "Initial CPU loads:\n";
    for (int x = 0; x < n; x++) {
        r = ins(r, a[x][0], a[x][1]);
        cout << "CPU " << a[x][0] << ": " << a[x][1] << "%\n";
    }
    cout << "\nAssigning new processes:\n";
    for (int x = 0; x < 3; x++) {
        Node* t = least(r);
        cout << "Process -> CPU " << t->id << " (load " << t->l << "%)\n";
        r = del(r, t->id, t->l);
        r = ins(r, t->id, t->l + 10);
    }
    cout << "\nAfter processes:\n";
    for (int x = 0; x < 2; x++) {
        Node* t = least(r);
        cout << "CPU " << t->id << " finished 1 process.\n";
        r = del(r, t->id, t->l);
        r = ins(r, t->id, t->l - 10);
    }
    cout << "\nLeast loaded CPU now: ";
    Node* z = least(r);
    cout << z->id << " (" << z->l << "%)\n";
}
