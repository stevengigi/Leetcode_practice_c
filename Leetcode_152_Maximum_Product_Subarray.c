int max(int a,int b){
    return (a>b)?a:b;
}

int min(int a,int b){
    return (a>b)?b:a;
}

int maxProduct(int* nums, int numsSize){
    int currmax=1,currmin=1;
    int res=INT_MIN;
    for(int i=0;i<numsSize;i++){
        res=max(res,nums[i]);
        if(nums[i]==0){
            currmax=1;
            currmin=1;
            continue;
        }
        int temp=currmax;
        currmax=max(currmax*nums[i],max(nums[i],currmin*nums[i]));
        currmin=min(temp*nums[i],min(currmin*nums[i],nums[i]));
        res=max(res,currmax);
        printf("currmax: %d | currmin:%d | res: %d\n",currmax,currmin,res);
    }
    return res;
}