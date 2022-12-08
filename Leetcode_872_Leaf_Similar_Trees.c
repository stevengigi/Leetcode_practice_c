/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void getvalue(struct TreeNode* root,int *arr,int *index){
    if(!root) return;
    else if(root->left==NULL && root->right==NULL){
        arr[(*index)++]=root->val;
    }else{
        getvalue(root->left,arr,index);
        getvalue(root->right,arr,index);
    }
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2){
    int *arr1=(int*)calloc(100,sizeof(int));
    int *arr2=(int*)calloc(100,sizeof(int));
    int index1=0;
    int index2=0;
    getvalue(root1,arr1,&index1);
    getvalue(root2,arr2,&index2);
    for(int i=0;i<100;i++){
        if(arr1[i]!=arr2[i]){
            return false;
        }
    }
    return true;
}