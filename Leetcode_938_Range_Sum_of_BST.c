/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumup(struct TreeNode* root,int low ,int high,int sum){
    if(!root) return sum;

    if(root->val < low){
        return sumup(root->right,low,high,sum);
    }else if(root->val > high){
        return sumup(root->left,low,high,sum);
    }else{
        return  sumup(root->left,low,high,sum)+sumup(root->right,low,high,sum)+sum+root->val;
    }
}


int rangeSumBST(struct TreeNode* root, int low, int high){

    return sumup(root,low,high,0);
}