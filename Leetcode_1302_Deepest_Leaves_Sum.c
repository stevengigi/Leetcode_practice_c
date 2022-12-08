/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a,int b){
    return a>b?a:b;
}

void depthsum(struct TreeNode* root,int *sum,int *maxdepth,int curdepth){
    if(!root) return;
    printf("curdepth : %d | maxdepth : %d | sum : %d \n",curdepth,maxdepth,*sum);
    if(*maxdepth < curdepth){
        *sum=root->val;
        *maxdepth=curdepth;
    }else if(*maxdepth == curdepth){
        *sum=*sum+root->val;
    }
    depthsum(root->left,sum,maxdepth,curdepth+1);
    depthsum(root->right,sum,maxdepth,curdepth+1);
}

int deepestLeavesSum(struct TreeNode* root){
    int sum=0;
    int maxdepth=-1;
    depthsum(root,&sum,&maxdepth,0);
    return sum;
}