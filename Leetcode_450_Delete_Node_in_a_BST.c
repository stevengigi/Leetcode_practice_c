/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *findmin(struct TreeNode* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key){
    if(!root) return NULL;

    if(root->val > key){
        root->left=deleteNode(root->left,key);
    }
    else if(root->val < key){
        root->right=deleteNode(root->right,key);
    }
    else{
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;

        struct TreeNode *min=findmin(root->right);
        root->val=min->val;
        root->right=deleteNode(root->right,root->val);
    }
    return root;
}