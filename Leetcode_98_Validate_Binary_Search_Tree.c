/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool valid(struct TreeNode *node,long left ,long right){
    if(node==NULL){
        return true;
    }
    if(!(node->val > left && node->val < right)){
        return false;
    }
    return (valid(node->left,left,node->val) && valid(node->right,node->val, right));
}

bool isValidBST(struct TreeNode* root){
    return valid(root,LONG_MIN,LONG_MAX);
}