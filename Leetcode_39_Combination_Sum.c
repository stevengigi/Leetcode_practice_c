

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}

void backtrack(int *nums,int numsize,int target,int start,int index,int *returnSize,int**returnColumnSizes,int **res,int *temp){
    if(target==0){
        res[*returnSize]=(int*)calloc(index,sizeof(int));
        memcpy(res[*returnSize],temp,index*sizeof(int));
        (*returnColumnSizes)[*returnSize]=index;
        (*returnSize)++;
    }else{
        for(int i=start;i<numsize;i++){
            if(target-nums[i] < 0) break;
            temp[index]=nums[i];
            backtrack(nums,numsize,target-nums[i],i,index+1,returnSize,returnColumnSizes,res,temp);
        }
    }
}


int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(candidates,candidatesSize,sizeof(int),cmp);
    for(int i=0;i<candidatesSize;i++){
        printf(" %d ",candidates[i]);
    }
    int **res=(int**)malloc(sizeof(int*)*200);
    int *temp=(int*)calloc(500,sizeof(int));
    *returnColumnSizes=(int*)calloc(200,sizeof(int));
    *returnSize=0;
    backtrack(candidates,candidatesSize,target,0,0,returnSize,returnColumnSizes,res,temp);
    free(temp);
    return res;
}