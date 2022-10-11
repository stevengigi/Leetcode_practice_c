int max(int a,int b){
    return (a>b)?a:b;
}

int longestNiceSubarray(int* nums, int numsSize){
    int res=1;
    int used=0;
    int j=0;
    for(int i=0;i<numsSize;i++){
        while((used & nums[i]) !=0){
            used ^=nums[j++];
        }
        used |=nums[i];
        res=max(res,i-j+1);
    }
    return res;
}