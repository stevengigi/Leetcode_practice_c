/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int helper(struct TreeNode* root,int p,int gp){
    if(!root) return 0;
    return helper(root->left,root->val,p)+helper(root->right,root->val,p)+(gp%2==0?root->val:0);
}

int sumEvenGrandparent(struct TreeNode* root){
    return helper(root,1,1);
}