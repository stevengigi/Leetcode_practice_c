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
int height(struct TreeNode* root){
    if(!root) return 0;
    int left=height(root->left)+1;
    int right=height(root->right)+1;
    return right>left?right:left;
}
void dfs(struct TreeNode* root,int **res,int index,int **returnColumnSizes){
    if(!root) return;
    res[index][(*returnColumnSizes)[index]]=root->val;
    (*returnColumnSizes)[index]++;
    dfs(root->left,res,index-1,returnColumnSizes);
    dfs(root->right,res,index-1,returnColumnSizes);
}
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int depth=height(root);
    *returnSize=depth;
    *returnColumnSizes=(int*)calloc(depth,sizeof(int));
    int **res=(int**)malloc(sizeof(int*)*depth);
    for(int i=0;i<depth;i++){
        res[i]=(int*)calloc(200,sizeof(int));
    }
    dfs(root,res,depth-1,returnColumnSizes);
    return res;
}


