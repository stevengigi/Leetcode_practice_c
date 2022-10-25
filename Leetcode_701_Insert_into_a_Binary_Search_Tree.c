/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* creatnode(){
    struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->left=NULL;
    node->right=NULL;
    return node;
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    if(!root){
        root=creatnode();
        root->val=val;
        return root;
    }
    if(root->val < val){
        if(!root->right){
            root->right=creatnode();
            root->right->val=val;
        }else{
            insertIntoBST(root->right,val);
        }
        return root;
    }
    else{
        if(!root->left){
            root->left=creatnode();
            root->left->val=val;
        }else{
            insertIntoBST(root->left,val);
        }
        return root;
    }
    return root;
}