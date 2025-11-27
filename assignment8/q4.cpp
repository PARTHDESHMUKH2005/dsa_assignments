bool isBSTUtil(BSTNode* root, int minVal, int maxVal){
    if(!root) return true;
    if(root->data < minVal || root->data > maxVal) return false;
    return isBSTUtil(root->left,minVal,root->data-1) &&
           isBSTUtil(root->right,root->data+1,maxVal);
}

bool isBST(BSTNode* root){
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
