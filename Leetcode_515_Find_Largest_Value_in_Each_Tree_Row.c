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
    return a>b?a:b;
}

int maxdepth(struct TreeNode* root){
    if(!root) return 0;
    int left=maxdepth(root->left);
    int right=maxdepth(root->right);
    int temp=max(left,right);
    return temp+1;
}

void findmin(struct TreeNode* root,int *arr,int d,int depth){
    if(!root || d==depth) return;
    arr[d]=max(arr[d],root->val);
    findmin(root->left,arr,d+1,depth);
    findmin(root->right,arr,d+1,depth);

}

int* largestValues(struct TreeNode* root, int* returnSize){
    int depth=maxdepth(root);
    printf("depth : %d\n",depth);
    int *arr=(int*)malloc(sizeof(int)*depth);
    for(int i=0;i<depth;i++){
        arr[i]=INT_MIN;
    }
    *returnSize=depth;
    findmin(root,arr,0,depth);
    return arr;
}