bool findNode(struct TreeNode* root, int k){
    if(root==NULL) return false;
    if(root->val<k) return findNode(root->right, k);
    if(root->val>k) return findNode(root->left, k);
    return true;
}

bool findTarget2(struct TreeNode* root1, struct TreeNode* root2, int k){
    if(root1==NULL) return false;
    return findNode(root2, k-root1->val) || findTarget2(root1->left, root2, k) || findTarget2(root1->right, root2, k);
}

bool findTarget(struct TreeNode* root, int k){
    if(root==NULL) return false;
    if(2*root->val<k) return findNode(root->right, k-root->val) || findTarget(root->right, k) || findTarget2(root->left, root->right, k);
    if(2*root->val>k) return findNode(root->left, k-root->val) || findTarget(root->left, k) || findTarget2(root->left, root->right, k);
    return findTarget2(root->left, root->right, k);
}
