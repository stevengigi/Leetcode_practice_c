/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a,int b){
    return a>=b?a:b;
}

int depth(struct TreeNode* root){
    if(!root) return 0;
    return 1+max(depth(root->right),depth(root->left));
}

bool isBalanced(struct TreeNode* root){
    if(!root) return 1;
    int left=depth(root->left);
    int right=depth(root->right);
    printf("root : %d | right : %d | left :%d\n",root->val,right,left);
    return abs(left-right)<=1 && isBalanced(root->left) && isBalanced(root->right);
}

