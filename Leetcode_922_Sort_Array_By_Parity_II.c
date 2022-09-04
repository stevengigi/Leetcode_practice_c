

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize){
    *returnSize=numsSize;
    int *odd=(int*)malloc(sizeof(int)*(numsSize/2));
    int *even=(int*)malloc(sizeof(int)*(numsSize/2));
    int oddindex=0;
    int evenindex=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]%2==0){
            even[evenindex++]=nums[i];
        }else{
            odd[oddindex++]=nums[i];
        }
    }
    evenindex=0;
    oddindex=0;
    int *res=(int*)malloc(sizeof(int)*(numsSize));
    for(int i=0;i<numsSize;i++){
        if(i%2==0){
            res[i]=even[evenindex++];
        }else{
            res[i]=odd[oddindex++];
        }
    }
    free(odd);
    free(even);
    return res;
}