int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int min(int a,int b){
    return (a>b)?b:a;
}
int arrayPairSum(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(int),cmp);
    int max=0;

    for(int i=0;i<numsSize;i+=2){
        max+=nums[i];
    }
    return max;
}