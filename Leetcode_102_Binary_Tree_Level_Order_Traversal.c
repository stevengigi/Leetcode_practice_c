/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


int finddepth(struct TreeNode* root){
    if(!root) return 0;

    int left=finddepth(root->left)+1;
    int right=finddepth(root->right)+1;
    return left>right ? left :right;
}
void dfs(struct TreeNode *root , int **res, int index,int **returnColumnSizes){
    if(!root) return;
    res[index][(*returnColumnSizes)[index]]=root->val;
    (*returnColumnSizes)[index]++;
    dfs(root->left,res,index+1,returnColumnSizes);
    dfs(root->right,res,index+1,returnColumnSizes);
}
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int depth=finddepth(root);
    printf("%d",depth);
    *returnSize=depth;
    *returnColumnSizes=(int*)calloc(depth,sizeof(int));
    int **res=(int**)malloc(depth*sizeof(int*));
    for(int i=0;i<depth;i++){
        res[i]=(int*)malloc(sizeof(int)*250);
    }
    dfs(root,res,0,returnColumnSizes);
    return res;
}