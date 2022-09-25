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
int cmp(const void *a,const void *b){
    return *(int*)a -*(int*)b;
}

void dfs(struct TreeNode* root,int *index ,int *res){
    res[(*index)++]=root->val;
    if(root->left){
        dfs(root->left,index,res);
    }
    if(root->right){
        dfs(root->right,index,res);
    }
}

int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){
    *returnSize=0;
    int *res=(int *)calloc(10000,sizeof(int));
    int *index=(int*)calloc(1,sizeof(int));
    if(root1){
        dfs(root1,index,res);
    }
    if(root2){
        dfs(root2,index,res);
    }

    *returnSize=*index;
    res=(int*)realloc(res,(*index)*sizeof(int));
    qsort(res,*index,sizeof(int),cmp);
    return res;
}