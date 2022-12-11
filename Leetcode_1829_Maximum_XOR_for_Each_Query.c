/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize){
    int *res=(int*)malloc(sizeof(int)*numsSize);
    *returnSize=numsSize;
    int max=pow(2,maximumBit)-1;
    for(int i=1;i<numsSize;i++){
        nums[i]^=nums[i-1];
    }
    for(int i=0;i<numsSize;i++){
        res[i]=nums[numsSize-i-1]^max;
    }
    // for(int i=0;i<numsSize;i++){
    //     printf(" %d ",nums[i]);
    // }
    // printf("\n");
    // for(int i=0;i<numsSize;i++){
    //     printf(" %d ",res[i]);
    // }
    return res;
}
