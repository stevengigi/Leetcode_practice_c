/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode* root,bool isleft){
    if(!root) return 0;
    if(!root->left && !root->right) return isleft?root->val:0;
    return dfs(root->left,true) + dfs(root->right,false);
}

int sumOfLeftLeaves(struct TreeNode* root){
    return dfs(root,false);
}