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
    return a>b?a:b;
}

int maxdepth(struct TreeNode* root){
    if(!root) return 0;
    int right=maxdepth(root->right);
    int left=maxdepth(root->left);
    int temp=max(right,left);
    return temp+1;
}

void path(struct TreeNode* root,char ***res,int left,int right,int d,int depth){
    if(!root || d==depth) return;
    int mid=(right+left)/2;
    char *temp=(char*)malloc(sizeof(char)*4);
    sprintf(temp,"%d",root->val);
    res[d][mid]=temp;

    path(root->left,res,left,mid-1,d+1,depth);
    path(root->right,res,mid+1,right,d+1,depth);

}

char *** printTree(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int depth=maxdepth(root);

    int size=pow(2,depth)-1;
    printf("depth : %d | size : %d\n",depth,size);
    *returnColumnSizes=(int*)malloc(sizeof(int)*size);
    *returnSize=depth;

    char ***res=(char***)malloc(sizeof(char**)*depth);
    for(int i=0;i<depth;i++){
        // printf("ok\n");
        (*returnColumnSizes)[i]=size;
        res[i]=(char**)malloc(sizeof(char*)*size);
        // printf("ok1\n");
        for(int j=0;j<size;j++){
            // printf("ok2\n");
            res[i][j]="";
        }
    }

    path(root,res,0,size-1,0,depth);

    return res;
}