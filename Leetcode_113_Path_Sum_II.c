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
int max(int a,int b){
    return (a>b)?a:b;
}

int rooth(struct TreeNode* root){
    if(!root){
        return 0;
    }
    return 1+max(rooth(root->left),rooth(root->right));
}

void backtrack(struct TreeNode* root,int **res,int *temp,int pos,int target,  int* returnSize, int** returnColumnSizes){
    temp[pos]=root->val;
    pos++;
    if(!root->left && !root->right){
        if(target==root->val){
            res[*returnSize]=(int*)malloc(sizeof(int)*(pos));
            memcpy(res[*returnSize],temp,(pos)*sizeof(int));
            (*returnColumnSizes)[*returnSize]=pos;
            (*returnSize)++;
        }
        return;
    }

    if(root->left){
        backtrack(root->left,res,temp,pos,target-root->val,returnSize,returnColumnSizes);
    }
    if(root->right){
        backtrack(root->right,res,temp,pos,target-root->val,returnSize,returnColumnSizes);
    }
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes){
    int h=rooth(root);
    printf(" h :%d",h);
    if(h==0){
        *returnSize=0;
        return NULL;
    }
    int **res=(int**)malloc(sizeof(int*)*10000);
    int *temp=(int*)calloc(h,sizeof(int));

    *returnColumnSizes = (int*)malloc(2501 * sizeof(int));
    *returnSize=0;

    backtrack(root,res,temp,0,targetSum,returnSize,returnColumnSizes);

    res = (int**)realloc(res, (*returnSize) * sizeof(int*));
    *returnColumnSizes =(int*) realloc(*returnColumnSizes, (*returnSize)*sizeof(int));
    return res;
}



