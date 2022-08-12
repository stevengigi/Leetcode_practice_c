/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *curr=root;
    while(curr!=NULL){
        if(curr->val > q->val && curr->val > p->val){
            curr=curr->left;
        }else if(curr->val < q->val && curr->val < p->val){
            curr=curr->right;
        }else{
            return curr;
        }
    }
    return;
}