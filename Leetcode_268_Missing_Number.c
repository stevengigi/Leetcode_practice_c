

int missingNumber(int* nums, int numsSize){
    int res=0;
    for(int i=0;i<numsSize;i++){
        printf(" %d %d",i,nums[i]);
        res^=(i^nums[i]);
        // res^=nums[i];
    }
    return res^numsSize;
}