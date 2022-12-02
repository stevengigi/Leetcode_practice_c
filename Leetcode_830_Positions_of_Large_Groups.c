int** largeGroupPositions(char * s, int* returnSize, int** returnColumnSizes){
    int n = strlen(s);
    int** ans = malloc(n/3 * sizeof(int*));
    int idx = 0;
    int begin = 0;
    int cn =1;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1]){
            cn++;
        }
        else{
            if(cn >=3){
                ans[idx] = malloc(2 *sizeof(int));
                ans[idx][0] = begin;
                ans[idx][1] = i-1;
                idx++;
            }
            begin = i;
            cn =1;
        }
    }
   if(cn >=3){
     ans[idx] = malloc(2 *sizeof(int));
     ans[idx][0] = begin;
     ans[idx][1] = n-1;
     idx++;
   }
    *returnSize = idx;
    *returnColumnSizes = malloc(idx * sizeof(int));
    for(int i = 0; i < idx; i++){
        returnColumnSizes[0][i] = 2;
    }
    return ans;
}