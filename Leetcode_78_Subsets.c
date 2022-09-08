

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtrack(int *nums,int numsize,int size,int start,int index,int **res,int *temp,int *returnSize,int** returnColumnSizes){
    if(index==size){
        (*returnColumnSizes)[*returnSize]=size;
        res[(*returnSize)] = (int*)malloc(index * sizeof(int));
        if(size) memcpy(res[*returnSize],temp,sizeof(int)*index);
        (*returnSize)++;
    }else{
        for(int i=start;i<numsize;i++){
            temp[index]=nums[i];
            backtrack(nums,numsize,size,i+1,index+1,res,temp,returnSize,returnColumnSizes);
        }
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int size = pow(2, numsSize);
    *returnSize = 0;
    *returnColumnSizes = (int*) malloc(size * sizeof(int));
    int** res = (int**) malloc(size * sizeof(int*));
    int *temp=(int*)calloc(numsSize,sizeof(int));
    for(int i=0;i<=numsSize;i++){
        backtrack(nums,numsSize,i,0,0,res,temp,returnSize,returnColumnSizes);
    }
    return res;
}