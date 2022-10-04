/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool dfs(struct TreeNode* root, int targetSum,int sum){
    sum+=root->val;
    if(!root->right && !root->left){
        if(targetSum==sum){
            return true;
        }else{
            return false;
        }

    }
    else{
        printf(" %d \n",sum);

        bool right=false,left=false;
        if(root->right){
           right=dfs(root->right,targetSum,sum);
        }
        if(root->left){
            left=dfs(root->left,targetSum,sum);
        }
        return right | left;
    }
}

bool hasPathSum(struct TreeNode* root, int targetSum){
    if(root)
    return dfs(root,targetSum,0);
}