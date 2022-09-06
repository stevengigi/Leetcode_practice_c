
int findDuplicate(int* nums, int numsSize){
    int *t=(int*)calloc(numsSize,sizeof(int));
    for(int i=0;i<numsSize;i++){
        if(t[nums[i]]++) return nums[i];
        t[nums[i]]++;
    }
    return;
}