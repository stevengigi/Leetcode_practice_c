int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int max(int a,int b){
    return (a>b)?a:b;
}

int maxFrequency(int* nums, int numsSize, int k){
    qsort(nums,numsSize,sizeof(int),cmp);
    long long sum=0;
    int res=0;
    int j=0;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
        while(sum+k < (long long)nums[i] *(i-j+1)){
            sum-=nums[j++];
        }
        res=max(res,i-j+1);
    }
    return res;
}