/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 #define MOD 1000000007

long long max(long long a,long long b){
    return a>b?a:b;
}

int dfs(struct TreeNode* root){
    if(!root) return 0;
    return dfs(root->right)+dfs(root->left)+root->val;
}

int dfs2(struct TreeNode* root,long long totalsum,long long *rmax){
    if(!root) return 0;
    int left=dfs2(root->left,totalsum,rmax);
    int right=dfs2(root->right,totalsum,rmax);
    *rmax=max(*rmax,(long long)(totalsum-root->val-left-right)*(root->val+left+right));
    return left+right+root->val;

}

int maxProduct(struct TreeNode* root){
    long long  totalsum=dfs(root);
    long long  rmax=0;
    int sum=dfs2(root,totalsum,&rmax);
    printf("totalsum : %d | sum : %d \n",totalsum,sum);

    return (int)(rmax%MOD);
}