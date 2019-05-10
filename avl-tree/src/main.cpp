#include <iostream>

struct Node {
    unsigned char height;
    Node* left;
    Node* right;
    int key;
    Node(int k) {key = k; left = right = 0; height = 1;}
};

unsigned char height(Node* p) {
    return p ? p->height : 0;
}

int bal_factor(Node* p) {
    return height(p->right)-height(p->left);
}

void fix_height(Node* p) {
    unsigned char h_l = height(p->left);
    unsigned char h_r = height(p->right);
    p->height = (h_l>h_r?h_l:h_r) + 1;
}

Node* rotateright(Node* p) {
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    fix_height(p);
    fix_height(q);
    return q;
}

Node* rotateleft(Node* q) {
    Node* p = q->right;
    q->right = p->left;
    p->left = q;
    fix_height(q);
    fix_height(p);
    return p;
}

Node* balance(Node* p) {
    fix_height(p);
    if (bal_factor(p) == 2) {
        if (bal_factor(p->right) < 0)
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if (bal_factor(p) == -2) {
        if (bal_factor(p->left) < 0)
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
}

Node* insert_node(Node* parent, int k) {
    if(!parent)
        return new Node(k);
    if (k < parent->key)
        parent->left = insert_node(parent->left, k);
    else parent->right = insert_node(parent->right, k);
    //return balance(parent);
}

void delete_node() {

}

int main() {
    std::cout << "Hello Easy C++ project!" << std::endl;
}