/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int min(int a,int b){
    return a>b?b:a;
}

void findmin(struct TreeNode* root,int *pre,int* minval){
    if(!root) return;
    printf("root->val : %d\n",root->val);
    findmin(root->left,pre,minval);
    if(*pre >=0) *minval=min(*minval,root->val-*pre);
    *pre=root->val;
    findmin(root->right,pre,minval);

}

int minDiffInBST(struct TreeNode* root){
    int pre=-1;
    int minval=INT_MAX;
    findmin(root,&pre,&minval);
    return minval;
}