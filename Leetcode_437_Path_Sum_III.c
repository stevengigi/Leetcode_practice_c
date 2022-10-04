/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a,int b){
    return(a>b)?a:b;
}

int depth(struct TreeNode* root){
    if(!root)
        return 0;
    else
        return 1+max(depth(root->left),depth(root->right));
}

void dfs(struct TreeNode* root,int target,int *ans ,float  *arr ,int pos){
    arr[pos]=arr[pos-1]+root->val;
    int remain = arr[pos]-target;
    for(int i=pos-1;i>=0;i--){
        if(remain==arr[i]){
            *ans=*ans+1;
        }
    }
    pos++;
    if(root->right){
        // printf(" %d - go in right\n",*ans);
        dfs(root->right,target,ans,arr,pos);
    }
    if(root->left){
        // printf(" %d - go in left\n",*ans);
        dfs(root->left,target,ans,arr,pos);
    }
}

int pathSum(struct TreeNode* root, int targetSum){
    int h=depth(root);
    printf("h : %d",h);
    if(h==0) return 0;
    float *arr=(float*)calloc(h+1,sizeof(float));
    int *ans=(int*)calloc(1,sizeof(int));
    dfs(root,targetSum,ans,arr,1);
    int res=*ans;
    free(arr);
    free(ans);
    return res;

}