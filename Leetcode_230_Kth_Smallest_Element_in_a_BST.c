//Method 1
int kthSmallest(struct TreeNode* root, int k){
    struct TreeNode **stack=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*10000);
    struct TreeNode *curr=root;
    int top=-1;
    int n=0;
    while(curr!=NULL || top!=-1){
        while(curr!=NULL){
            stack[++top]=curr;

            curr=curr->left;
        }
        curr=stack[top--];
        printf(" %d ",curr->val);
        n++;
        if(n==k){
            printf("\n return curr->val : %d \n",curr->val);
            return curr->val;
        }
        curr=curr->right;
    }
    free(stack);
    return;
}

// Method2
void find(struct TreeNode *root,int *ans,int *k){
    if(root==NULL){
        return;
    }
    find(root->left,ans,k);
    (*k)--;
    if(*k==0){
        *ans=root->val;
        return;
    }
    find(root->right,ans,k);

}

int kthSmallest(struct TreeNode* root, int k){
    int ans=0;
    find(root,&ans,&k);
    return ans;
}