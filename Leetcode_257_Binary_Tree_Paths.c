char* dataToStr(int* data, int data_size){
    char* ans = malloc(data_size * 5 * sizeof(char));
    int id = 0;
    int temp;
    for(int i = 0; i < data_size; i++){
        if(data[i] < 0){
            ans[id] = '-';
            id++;
        }
        temp = abs(data[i]);
        if(temp == 100){
            ans[id] = '1';
            id++;
            ans[id] = '0';
            id++;
            ans[id] = '0';
            id++;
        }
        else{
            if(temp >=10){
                ans[id] = temp/10 + '0';
                id++;
            }
            ans[id] = temp%10 + '0';
            id++;
        }
        if(i < (data_size -1)){
            ans[id] = '-';
            id++;
            ans[id] = '>';
            id++;
        }
    }
    ans[id] = '\0';
    return ans;

}
void process(struct TreeNode* root, char** ans, int* idx, int* data, int data_idx ){
    if(root == NULL)
        return;
    data[data_idx] = root->val;
    data_idx++;
    if(root->left == NULL && root->right == NULL){
        ans[*idx] = dataToStr(data, data_idx);
        *idx = *idx + 1;
        return;
    }
    process(root->left, ans, idx, data, data_idx);
    process(root->right, ans, idx, data, data_idx);
}
char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    char** ans = malloc(50 * sizeof(char*));
    int* data = malloc(100 * sizeof(int));
    *returnSize = 0;

    process(root, ans, returnSize, data, 0);
    ans = realloc(ans, (*returnSize) * sizeof(char*));

    return ans;
}