/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int dfs(struct TreeNode* root,int val){
    if(!root) return 0;
    if(root->left==NULL && root->right==NULL){
        return val*10+root->val;
    }
    return dfs(root->left,val*10+root->val)+dfs(root->right,val*10+root->val);
}

int sumNumbers(struct TreeNode* root){
    int sum=dfs(root,0);
    return sum;
}