/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool check(struct TreeNode* right,struct TreeNode* left){
    if(right==NULL && left==NULL){
        return true;
    }
    if((left!=NULL && right==NULL) || (right!=NULL && left==NULL) || left->val!=right->val){
        return false;
    }
    return check(right->left,left->right) && check(right->right,left->left);
}

bool isSymmetric(struct TreeNode* root){
    if(!root) return true;
    return check(root->right,root->left);
}

