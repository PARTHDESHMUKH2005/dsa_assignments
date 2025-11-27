#include <iostream>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* insert(BSTNode* root, int key){
    if(!root) return new BSTNode{key,nullptr,nullptr};
    if(key < root->data) root->left = insert(root->left,key);
    else if(key > root->data) root->right = insert(root->right,key);
    return root; // duplicates ignored
}

// (a) Search Recursive
bool searchRecursive(BSTNode* root, int key){
    if(!root) return false;
    if(root->data == key) return true;
    if(key < root->data) return searchRecursive(root->left,key);
    else return searchRecursive(root->right,key);
}

// (a) Search Non-Recursive
bool searchIterative(BSTNode* root, int key){
    while(root){
        if(root->data == key) return true;
        else if(key < root->data) root = root->left;
        else root = root->right;
    }
    return false;
}

// (b) Maximum
int findMax(BSTNode* root){
    if(!root) throw runtime_error("Empty BST");
    while(root->right) root = root->right;
    return root->data;
}

// (c) Minimum
int findMin(BSTNode* root){
    if(!root) throw runtime_error("Empty BST");
    while(root->left) root = root->left;
    return root->data;
}

// (d) In-order successor
BSTNode* inOrderSuccessor(BSTNode* root, BSTNode* node){
    if(node->right){
        BSTNode* temp = node->right;
        while(temp->left) temp = temp->left;
        return temp;
    }
    BSTNode* succ = nullptr;
    while(root){
        if(node->data < root->data){
            succ = root;
            root = root->left;
        } else if(node->data > root->data)
            root = root->right;
        else break;
    }
    return succ;
}

// (e) In-order predecessor
BSTNode* inOrderPredecessor(BSTNode* root, BSTNode* node){
    if(node->left){
        BSTNode* temp = node->left;
        while(temp->right) temp = temp->right;
        return temp;
    }
    BSTNode* pred = nullptr;
    while(root){
        if(node->data > root->data){
            pred = root;
            root = root->right;
        } else if(node->data < root->data)
            root = root->left;
        else break;
    }
    return pred;
}
