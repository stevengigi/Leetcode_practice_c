/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int max(int a,int b){
    return (a>b)?a:b;
}

int height(struct TreeNode* root){
    if(!root) return 0;
    return 1+max(height(root->right),height(root->left));
}

void postorder(struct TreeNode* root,int *arr,int *index){
    if(!root) return;
    postorder(root->left,arr,index);
    postorder(root->right,arr,index);
    arr[(*index)++]=root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int h=height(root);
    *returnSize=0;
    if(!h) return NULL;
    // printf("h : %d\n %d",h,pow(2,h));
    int temp=pow(2,h);
    int *arr=(int*)malloc(sizeof(int)*temp);
    int *index=(int*)calloc(1,sizeof(int));
    postorder(root->left,arr,index);
    postorder(root->right,arr,index);
    arr[*index]=root->val;
    // arr=(int*)realloc(arr,*index+1);
    *returnSize=*index+1;
    free(index);
    return arr;
}