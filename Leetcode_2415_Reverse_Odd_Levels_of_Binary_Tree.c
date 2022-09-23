/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode* root1,struct TreeNode* root2,int level){
    if(!root1 || !root2){
        return;
    }
    if(level%2==1){
        int val=root1->val;
        root1->val=root2->val;
        root2->val=val;
    }
    dfs(root1->left,root2->right,level+1);
    dfs(root1->right,root2->left,level+1);

}

struct TreeNode* reverseOddLevels(struct TreeNode* root){
    int level=0;
    dfs(root->left,root->right,level+1);
    return root;
}