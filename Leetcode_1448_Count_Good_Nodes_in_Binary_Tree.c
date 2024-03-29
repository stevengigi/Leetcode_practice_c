/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool max(int a,int b){
    return a>=b?1:0;
}
void findnode(struct TreeNode* root,int *res,int max){
    if(!root) return;
    if(root->val >= max){
        max=root->val;
        (*res)++;
    }
    findnode(root->left,res,max);
    findnode(root->right,res,max);

}

int goodNodes(struct TreeNode* root){
    int res=1;
    findnode(root->left,&res,root->val);
    findnode(root->right,&res,root->val);
    return res;
}