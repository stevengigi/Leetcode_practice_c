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
int dfs(struct TreeNode* root ,int height,int *array){
    if(root==NULL){
        return  height;
    }
    array[height]=root->val;

    int left=dfs(root->left,height+1,array);
    int right=dfs(root->right,height+1,array);

    return (left>right)?left:right;
}

int* rightSideView(struct TreeNode* root, int* returnSize){
    if(root==NULL){
        *returnSize=0;
        return NULL;
    }
    int *array=(int*)calloc(100,sizeof(int));
    *returnSize=dfs(root,0,array);

    return array;
}