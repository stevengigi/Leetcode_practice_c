/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



void dfs(struct TreeNode *root,int *sum){
    if(root==NULL){
        return;
    }else{
        dfs(root->right,sum);
        (*sum)+=root->val;
        root->val=*sum;
        dfs(root->left,sum);
    }
}

struct TreeNode* convertBST(struct TreeNode* root){
    struct TreeNode *head=root;
    int sum=0;
    dfs(head,&sum);
    return root;
}