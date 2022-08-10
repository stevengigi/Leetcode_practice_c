/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *creatroot(int val){
    struct TreeNode *root=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val=val;
    root->left=NULL;
    root->right=NULL;
    return root;
}

struct TreeNode *helper(struct TreeNode *root,int *nums,int l, int r){
    if(l>r){
        return;
    }
    int m=(l+r)/2;

    root=creatroot(nums[m]);
    root->left=helper(root,nums,l,m-1);
    root->right=helper(root,nums,m+1,r);
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    struct TreeNode *root=NULL;
    return helper(root,nums,0,numsSize-1);
}