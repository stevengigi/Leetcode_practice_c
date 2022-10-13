// [1 2 3 4]
// [1 2 3 4]

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtrack(int **res,int *temp,int pos,int* nums, int numsSize, int* returnSize, int** returnColumnSizes,int *visit){
    if(pos==numsSize){
        int *copy=(int*)calloc(pos,sizeof(int));
        memcpy(copy,temp,sizeof(int)*pos);
        res[*returnSize]=copy;
        (*returnColumnSizes)[*returnSize]=numsSize;
        (*returnSize)++;
    }else{
        for(int i=0;i<numsSize;i++){
            if(visit[i]==0){
                visit[i]=1;
                temp[pos]=nums[i];
                backtrack(res,temp,pos+1,nums,numsSize,returnSize,returnColumnSizes,visit);
                visit[i]=0;
            }
        }
    }
}
int num(int a){
    int ans=1;
    while(a>1){
        ans*=a;
        a--;
    }
    return ans;
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int size=num(numsSize);
    printf("size : %d\n",size);
    *returnSize=0;
    *returnColumnSizes=(int*)malloc(sizeof(int)*size);
    int **res=(int**)malloc(sizeof(int*)*size);
    int *temp=(int*)calloc(numsSize,sizeof(int));
    int *visit=(int*)calloc(numsSize,sizeof(int));
    for(int i=0;i<numsSize;i++){
        int pos=0;
        visit[i]=1;
        temp[pos]=nums[i];
        backtrack(res,temp,pos+1,nums,numsSize,returnSize,returnColumnSizes,visit);
        visit[i]=0;
    }
    free(temp);
    return res;
}

