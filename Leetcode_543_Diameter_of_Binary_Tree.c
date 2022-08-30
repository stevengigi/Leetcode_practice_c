/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a,int b){
    return (a>b)?a:b;
}
int dfs(struct TreeNode* root,int *ans){
    if(root==NULL){
        return 0;
    }
    int right=dfs(root->right,ans);
    int left=dfs(root->left,ans);
    *ans=max(*ans,left+right);
    return 1+max(right,left);
}

int diameterOfBinaryTree(struct TreeNode* root){
    int ans=0;
    dfs(root,&ans);
    // int left=dfs(root->left,1);
    return ans;
}