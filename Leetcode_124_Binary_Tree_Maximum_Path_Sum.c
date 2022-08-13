/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// Reference :https://www.youtube.com/watch?v=Hr5cWUld4vU

int max(int a,int b){
    return (a>b)?a:b;
}

int dfs(struct TreeNode* root,int *res){
    if(root==NULL){
        return 0;
    }
    int leftmax=dfs(root->left,res);
    int rightmax=dfs(root->right,res);
    leftmax=max(leftmax,0);
    rightmax=max(rightmax,0);
    *res=max(*res,root->val+leftmax+rightmax);
    return root->val+max(leftmax,rightmax);

}

int maxPathSum(struct TreeNode* root){
    int res=root->val;
    dfs(root,&res);
    return res;

}