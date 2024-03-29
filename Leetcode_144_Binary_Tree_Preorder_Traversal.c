int nodeCount(struct TreeNode* root) {
    if (root==NULL)
        return 0;

    return (nodeCount(root->left)+ nodeCount(root->right)) + 1;
}

void preorder(struct TreeNode* root, int *res, int *size) {
    if(root==NULL)
        return;

    res[(*size)++] = root->val;
    preorder(root->left, res, size);
    preorder(root->right, res, size);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int lev = nodeCount(root);

    int *result =(int*)malloc(sizeof(int)*(lev+1));
    *returnSize = 0;

    preorder(root, result, returnSize);

    return result;
}