/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* root, int val, int depth,int temp){
    if(!root) return;
    if(depth-temp==1){
        struct TreeNode *left=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        struct TreeNode *right=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        left->val=val;
        right->val=val;
        left->left=root->left;
        left->right=NULL;
        right->right=root->right;
        right->left=NULL;
        root->left=left;
        root->right=right;
        return;
    }
    dfs(root->left,val,depth,temp+1);
    dfs(root->right,val,depth,temp+1);
}


struct TreeNode* addOneRow(struct TreeNode* root, int val, int depth){
    if(depth==1){
        struct TreeNode *newnode=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        newnode->val=val;
        newnode->left=root;
        newnode->right=NULL;
        return newnode;
    }
    dfs(root,val,depth,1);
    return root;
}