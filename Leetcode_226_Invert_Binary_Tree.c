/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){
    if(!root) return root;
    struct TreeNode *stack[100];
    int start=-1;
    int end=-1;
    stack[++end]=root;
    while(start!=end){
        struct TreeNode *node=stack[++start];
        struct TreeNode *left=node->left;
        node->left=node->right;
        node->right=left;
        if(node->left!=NULL){
            stack[++end]=node->left;
        }
        if(node->right){
            stack[++end]=node->right;
        }

    }
    return root;
 }