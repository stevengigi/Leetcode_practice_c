/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void dfs(struct Node *root,int *res,int *index){
    if(!root){
        return;
    }
    res[(*index)++]=root->val;
    for(int i=0;i<root->numChildren;i++){
        dfs(root->children[i],res,index);
    }
}

int* preorder(struct Node* root, int* returnSize) {
    *returnSize=0;
    int *res=(int*)malloc(sizeof(int)*10000);
    // printf("%d",root->children[1]->val);
    dfs(root,res,returnSize);
    res=(int*)realloc(res,sizeof(int)*(*returnSize));
    return res;
}