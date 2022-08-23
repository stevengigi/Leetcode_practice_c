/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void travel(struct TreeNode *root,int* count){
    if(root==NULL){
        return;
    }
    (*count)++;
    travel(root->left,count);
    travel(root->right,count);
    return;
}

int countNodes(struct TreeNode* root){
    int count=0;
    travel(root,&count);
    return count;
}