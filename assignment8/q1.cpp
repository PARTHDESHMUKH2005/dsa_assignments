#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Pre-order: Root -> Left -> Right
void preOrder(Node* root){
    if(!root) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// In-order: Left -> Root -> Right
void inOrder(Node* root){
    if(!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Post-order: Left -> Right -> Root
void postOrder(Node* root){
    if(!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Helper to create a new node
Node* createNode(int value){
    Node* newNode = new Node{value, nullptr, nullptr};
    return newNode;
}

// Example usage
int main(){
    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);

    cout << "Pre-order: "; preOrder(root); cout << endl;
    cout << "In-order: "; inOrder(root); cout << endl;
    cout << "Post-order: "; postOrder(root); cout << endl;

    return 0;
}
