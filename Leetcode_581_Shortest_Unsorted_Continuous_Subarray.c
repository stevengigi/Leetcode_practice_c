
// Method 1 sort
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int max(int a,int b){
    return (a>b)?a:b;
}
int min(int a,int b){
    return (a>b)?b:a;
}
int findUnsortedSubarray(int* nums, int numsSize){
    int copy[numsSize];
    memcpy(copy, nums, numsSize * sizeof(int));
    qsort(nums,numsSize,sizeof(int),cmp);
    int start=numsSize;
    int end=0;
    for(int i=0;i<numsSize;i++){
        if(copy[i] != nums[i]){
            start=min(start,i);
            end=max(end,i);
        }
    }
    return ((end-start)>0)?end-start+1:0;

}

