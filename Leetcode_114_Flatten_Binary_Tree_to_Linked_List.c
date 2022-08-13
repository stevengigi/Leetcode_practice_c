/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Reference : https://www.youtube.com/watch?v=rKnD7rLT0lI

struct TreeNode *dfs(struct TreeNode *root){
    if(root==NULL){
        return NULL;
    }
    struct TreeNode *lefttail;
    struct TreeNode *righttail;

    lefttail=dfs(root->left);
    righttail=dfs(root->right);

    if(root->left!=NULL){
        lefttail->right=root->right;
        root->right=root->left;
        printf("%d %d\n",root->left->val,lefttail->val);
        root->left=NULL;
    }
    if(righttail){
        return righttail;
    }else if(lefttail){
        return lefttail;
    }else{
        return root;
    }

}

void flatten(struct TreeNode* root){
    return dfs(root);
}