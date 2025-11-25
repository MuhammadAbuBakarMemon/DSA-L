#include <iostream>
using namespace std;

class Node {
public:
    int id, amt, h;
    Node *l, *r;
    Node(int a, int b) {
        id = a;
        amt = b;
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

Node* ins(Node* z, int id, int amt) {
    if (!z) return new Node(id, amt);
    if (amt < z->amt || (amt == z->amt && id < z->id)) z->l = ins(z->l, id, amt);
    else z->r = ins(z->r, id, amt);
    z->h = max(gh(z->l), gh(z->r)) + 1;
    int bal = bf(z);
    if (bal > 1 && amt < z->l->amt) return rr(z);
    if (bal < -1 && amt > z->r->amt) return lr(z);
    if (bal > 1 && amt > z->l->amt) {
        z->l = lr(z->l);
        return rr(z);
    }
    if (bal < -1 && amt < z->r->amt) {
        z->r = rr(z->r);
        return lr(z);
    }
    return z;
}

Node* minNode(Node* z) {
    while (z->l) z = z->l;
    return z;
}

Node* del(Node* z, int id, int amt) {
    if (!z) return z;
    if (amt < z->amt || (amt == z->amt && id < z->id)) z->l = del(z->l, id, amt);
    else if (amt > z->amt || (amt == z->amt && id > z->id)) z->r = del(z->r, id, amt);
    else {
        if (!z->l || !z->r) {
            Node* t = z->l ? z->l : z->r;
            delete z;
            return t;
        } else {
            Node* t = minNode(z->r);
            z->id = t->id;
            z->amt = t->amt;
            z->r = del(z->r, t->id, t->amt);
        }
    }
    z->h = max(gh(z->l), gh(z->r)) + 1;
    int bal = bf(z);
    if (bal > 1 && bf(z->l) >= 0) return rr(z);
    if (bal > 1 && bf(z->l) < 0) {
        z->l = lr(z->l);
        return rr(z);
    }
    if (bal < -1 && bf(z->r) <= 0) return lr(z);
    if (bal < -1 && bf(z->r) > 0) {
        z->r = rr(z->r);
        return lr(z);
    }
    return z;
}

Node* maxNode(Node* z) {
    while (z->r) z = z->r;
    return z;
}

void top2(Node* z, Node*& m1, Node*& m2) {
    if (!z) return;
    if (!m1 || z->amt > m1->amt) {
        m2 = m1;
        m1 = z;
    } else if ((!m2 || z->amt > m2->amt) && z->amt < m1->amt)
        m2 = z;
    top2(z->l, m1, m2);
    top2(z->r, m1, m2);
}

int main() {
    Node* r = NULL;
    r = ins(r, 101, 850000);
    r = ins(r, 102, 870000);
    r = ins(r, 103, 865000);
    r = ins(r, 104, 880000);
    r = ins(r, 105, 900000);
    Node* m1 = NULL; 
    Node* m2 = NULL;
    top2(r, m1, m2);
    if (m1) cout << "1st: " << m1->id << " " << m1->amt << "\n";
    if (m2) cout << "2nd: " << m2->id << " " << m2->amt << "\n";
    r = ins(r, 106, 920000);
    m1 = m2 = NULL;
    top2(r, m1, m2);
    if (m1) cout << "1st: " << m1->id << " " << m1->amt << "\n";
    if (m2) cout << "2nd: " << m2->id << " " << m2->amt << "\n";
    r = del(r, 104, 880000);
    m1 = m2 = NULL;
    top2(r, m1, m2);
    if (m1) cout << "1st: " << m1->id << " " << m1->amt << "\n";
    if (m2) cout << "2nd: " << m2->id << " " << m2->amt << "\n";
    cout << "Winner: " << m1->id << " " << m1->amt << "\n";
}
