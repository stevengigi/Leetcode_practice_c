

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}

int* findErrorNums(int* nums, int numsSize, int* returnSize){
    qsort(nums,numsSize,sizeof(int),cmp);
    int n=numsSize;
    // int count[n];
    int *res=(int*)calloc(2,sizeof(int));
    for(int i=0;i<n;i++){
        res[1]^=(i+1)^nums[i]; // a^b^b^b
        if(i>0 && nums[i]==nums[i-1]){
            res[0]=nums[i]; // b
        }
    }
    *returnSize=2;
    res[1]^=res[0];
    return res;
}