/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int maxdepth(struct Node* root){
    if(root==NULL){
        return 0;
    }
    if(root->numChildren==0){
        return 1;
    }
    int max=0;
    for(int i=0;i<root->numChildren;i++){
        int temp=maxdepth(root->children[i])+1;
        max= temp > max ? temp : max;
    }
    return max;
}

void addvalue(struct Node* root,int **res,int index,int **returnColumnSizes){
    if(root==NULL){
        return;
    }
    res[index][(*returnColumnSizes)[index]]=root->val;
    (*returnColumnSizes)[index]++;
    for(int i=0;i<root->numChildren;i++){
        addvalue(root->children[i],res,index+1,returnColumnSizes);
    }
}

int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    int depth=maxdepth(root);
    *returnSize=depth;
    int **res=(int**)malloc(sizeof(int*)*depth);
    *returnColumnSizes=(int*)calloc(depth,sizeof(int));
    for(int i=0;i<depth;i++){
        res[i]=(int*)malloc(sizeof(int)*10000);
    }
    addvalue(root,res,0,returnColumnSizes);
    return res;
}




