//
// Created by Trong_Phuc on 26/07/2023.
//

#ifndef AVL_TREE_AVLTREE_H
#define AVL_TREE_AVLTREE_H

#include <iostream>

using namespace std;

class Node { // AVL Tree Node
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int key) {
        this->key = key;
        left = right = nullptr;
        height = 1;
    }
};

class AVLTree { // AVL Tree Class
public:
    Node* root = nullptr;

    AVLTree() {
        root = nullptr;
    }
    static int get_height(Node* node);
    static int get_balance(Node* node);
    static Node* right_rotate(Node* y);
    static Node* left_rotate(Node* x);
    Node* insert_node(Node* node, int key);
    static Node* get_min_value_node(Node* node);
    Node* delete_node(Node* myRoot, int key);
    Node* search_node(Node* node, int key);
    void inorder(Node* node);
    void preorder(Node* node);
    void postorder(Node* node);
};

int AVLTree::get_height(Node *node) {
    if (node == nullptr) return 0;
    return node->height;
}

int AVLTree::get_balance(Node *node) {
    if (node == nullptr) return 0;
    return get_height(node->left) - get_height(node->right);
}

Node *AVLTree::right_rotate(Node *y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;
    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    cout << "Performing right rotation on node with key: " << y->key << endl;
    return x;
}

Node *AVLTree::left_rotate(Node *x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;
    cout << "Performing left rotation on node with key: " << x->key << endl;
    return y;
}

Node *AVLTree::insert_node(Node *node, int key) {
    if (node == nullptr) return new Node(key);

    if (key < node->key) node->left = insert_node(node->left, key);
    else if (key > node->key) node->right = insert_node(node->right, key);
    else return node;

    node->height = 1 + max(get_height(node->left), get_height(node->right));

    int balance = get_balance(node);
    if (balance > 1 && key < node->left->key) return right_rotate(node);
    if (balance < -1 && key > node->right->key) return left_rotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    return node;
}

Node *AVLTree::get_min_value_node(Node *node) {
    Node* current = node;
    while (current->left != nullptr) current = current->left;
    return current;
}

Node *AVLTree::delete_node(Node *myRoot, int key) {
    if (myRoot == nullptr) return myRoot;
    
    if (key < myRoot->key) {
        myRoot->left = delete_node(myRoot->left, key);
    } else if (key > myRoot->key) {
        myRoot->right = delete_node(myRoot->right, key);
    } else {
        if ((myRoot->left == nullptr) || (myRoot->right == nullptr)) {
            Node* temp = myRoot->left ? myRoot->left : myRoot->right;
            if (temp == nullptr) {
                temp = myRoot;
                myRoot = nullptr;
            } else {
                *myRoot = *temp;
            }
            free(temp);
        } else {
            Node* temp = get_min_value_node(myRoot->right);
            myRoot->key = temp->key;
            myRoot->right = delete_node(myRoot->right, temp->key);
        }
    }
    if (myRoot == nullptr) return myRoot;

    myRoot->height = 1 + max(get_height(myRoot->left), get_height(myRoot->right));
    int balance = get_balance(myRoot);
    if (balance > 1 && get_balance(myRoot->left) >= 0) return right_rotate(myRoot);
    if (balance < -1 && get_balance(myRoot->right) <= 0) return left_rotate(myRoot);
    if (balance > 1 && get_balance(myRoot->left) < 0) {
        myRoot->left = left_rotate(myRoot->left);
        return right_rotate(myRoot);
    }
    if (balance < -1 && get_balance(myRoot->right) > 0) {
        myRoot->right = right_rotate(myRoot->right);
        return left_rotate(myRoot);
    }
    return myRoot;
}

Node *AVLTree::search_node(Node *node, int key) {
    if (node == nullptr || node->key == key) return node;
    if (node->key < key) return search_node(node->right, key);
    return search_node(node->left, key);
}

void AVLTree::inorder(Node *node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->key << " ";
    inorder(node->right);
}

void AVLTree::preorder(Node *node) {
    if (node == nullptr) return;
    cout << node->key << " ";
    preorder(node->left);
    preorder(node->right);
}

void AVLTree::postorder(Node *node) {
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->key << " ";
}

#endif //AVL_TREE_AVLTREE_H
