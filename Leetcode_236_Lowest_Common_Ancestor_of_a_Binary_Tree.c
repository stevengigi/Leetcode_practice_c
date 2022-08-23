/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *res;

bool find(struct TreeNode* root,struct TreeNode* p, struct TreeNode* q){
    if(root==NULL){
        return NULL;
    }
    int left=find(root->left,p,q)?1:0;
    int right=find(root->right,p,q)?1:0;
    int mid=(root->val==q->val || root->val == p->val)?1:0;
    if(mid+left+right >= 2){
        res=root;
    }
    return (mid+left+right)>0;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    find(root,p,q);
    return res;
}