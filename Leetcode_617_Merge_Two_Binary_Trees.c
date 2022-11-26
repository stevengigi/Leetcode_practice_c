/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2){
    if(!root1) return root2;
    if(!root2) return root1;
    root1->val+=root2->val;
    root1->right=mergeTrees(root1->right,root2->right);
    root1->left=mergeTrees(root1->left,root2->left);
     return root1;
}