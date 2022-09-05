int depth(struct TreeNode* root){
    if(!root) return 0;
    int left=depth(root->left)+1;
    int right=depth(root->right)+1;
    return left>right? left:right;
}

int maxDepth(struct TreeNode* root){
    return depth(root);
}