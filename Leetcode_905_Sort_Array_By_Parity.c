

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    *returnSize=numsSize;
    int changeindex=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]%2==0){
            swap(&nums[i],&nums[changeindex++]);
        }
    }
    return nums;
}