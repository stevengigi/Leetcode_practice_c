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

//Inorder : 先拜訪左節點 在拜訪父節點 最後是右節點
//Recursive
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    // if(root==NULL){
    //     return NULL;
    // }
    *returnSize=0;
    int *res=(int*)malloc(sizeof(int)*100);
    inorder(root,res,returnSize);
    return res;
}

void inorder(struct TreeNode* root ,int *res, int* returnSize){
    if(root==NULL){
       return;
    }
    inorder(root->left,res,returnSize);
    res[(*returnSize)++]=root->val;
    inorder(root->right,res,returnSize);
}

//Iterative
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    struct TreeNode *stack[100];
    int top=-1;
    int size=0;
    int *res=(int*)malloc(sizeof(int)*100);
    while(root || top!=-1){
        while(root){
            stack[++top]=root;
            root=root->left;
        }
        root=stack[top--];
        res[size++]=root->val;
        root=root->right;
    }
    *returnSize=size;
    return res;
}