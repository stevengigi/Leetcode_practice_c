/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int min(int a,int b){
    return (a>b)?b:a;
}

int minDepth(struct TreeNode* root){
    if(!root) return 0;
    int right=minDepth(root->right);
    int left=minDepth(root->left);
    // printf("left : %d right : %d",left,right);
    return (left==0 || right==0)? left+right+1 : min(right,left)+1;
}