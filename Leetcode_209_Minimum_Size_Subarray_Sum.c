int min(int a,int b){
    return (a>b)?b:a;
}

int minSubArrayLen(int target, int* nums, int numsSize){
    int left=0;
    int sum=0;
    int res=INT_MAX;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
        while(sum>=target){
            res=min(res,i-left+1);
            sum-=nums[left++];
        }
    }
    return (res!=INT_MAX)?res:0;
}