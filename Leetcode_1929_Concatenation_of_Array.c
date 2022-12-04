/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize){
    int *arr=(int*)malloc(sizeof(int)*2*numsSize);
    *returnSize=2*numsSize;
    for(int i=0;i<numsSize;i++){
        arr[i+numsSize]=nums[i];
        arr[i]=nums[i];
    }
    return arr;
}