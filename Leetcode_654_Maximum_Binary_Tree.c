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

int findmax(int *nums,int left ,int right){
    int maxx=nums[left];
    int pos=left;
    for(int i=left+1;i<=right;i++){
        if(nums[i]>maxx){
            pos=i;
            maxx=nums[i];
        }
    }
    return pos;
}

struct TreeNode *construct(int *nums,int left ,int right){ // [left right]
    if(left==right+1){
        return NULL;
    }
    int pos=findmax(nums,left,right);
    printf(" %d ",pos);
    struct TreeNode *root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=nums[pos];
    root->left=construct(nums,left,pos-1);
    root->right=construct(nums,pos+1,right);
    return root;

}


struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
    return construct(nums,0,numsSize-1);
}