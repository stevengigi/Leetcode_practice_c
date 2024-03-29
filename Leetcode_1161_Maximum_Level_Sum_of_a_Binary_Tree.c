/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a,int b){
    return (a>b)?a:b;
}

int height(struct TreeNode* root){
    if(!root) return 0;
    else return 1+max(height(root->left),height(root->right));
}

void dfs(struct TreeNode* root,int *arr,int height){
    if(!root) return;
    arr[height]+=root->val;
    dfs(root->right,arr,height+1);
    dfs(root->left,arr,height+1);
}

int maxLevelSum(struct TreeNode* root){
    int h=height(root);
    if(h==1) return 1;
    int *temp=(int*)calloc(h+1,sizeof(int));
    dfs(root,temp,1);
    int ans=1;
    int res=temp[1];
    for(int i=2;i<=h;i++){
        if(temp[i]>res){
            res=temp[i];
            ans=i;
        }
    }
    free(temp);
    return ans;
}