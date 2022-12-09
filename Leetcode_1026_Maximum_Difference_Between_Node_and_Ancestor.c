void maxDiff(struct TreeNode* root, int min, int max, int* val) {
    if(root == NULL) return;

    if(root->val<min) min = root->val;
    if(root->val>max) max = root->val;
    if (*val < (max-min)) *val=max-min;
    printf("cur : %d | max : %d | min :%d | val : %d\n",root->val,max,min,*val);

    maxDiff(root->left, min, max, val);
    maxDiff(root->right, min, max, val);
}
int maxAncestorDiff(struct TreeNode* root){
    int min=0, max=0, val=0;
    if (root == NULL || (root->left==NULL && root->right==NULL)) return val;
    maxDiff(root, root->val, root->val, &val);
    return val;

}
