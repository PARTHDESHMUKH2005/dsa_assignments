// Delete a node
BSTNode* deleteNode(BSTNode* root, int key){
    if(!root) return nullptr;
    if(key < root->data) root->left = deleteNode(root->left,key);
    else if(key > root->data) root->right = deleteNode(root->right,key);
    else{
        if(!root->left){
            BSTNode* temp = root->right;
            delete root;
            return temp;
        } else if(!root->right){
            BSTNode* temp = root->left;
            delete root;
            return temp;
        } else {
            BSTNode* succ = root->right;
            while(succ->left) succ = succ->left;
            root->data = succ->data;
            root->right = deleteNode(root->right,succ->data);
        }
    }
    return root;
}

// Maximum depth
int maxDepth(BSTNode* root){
    if(!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return max(l,r)+1;
}

// Minimum depth
int minDepth(BSTNode* root){
    if(!root) return 0;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if(!root->left) return r+1;
    if(!root->right) return l+1;
    return min(l,r)+1;
}

