int max(int a,int b){
    return (a>b)?a:b;
}

int arrayNesting(int* nums, int numsSize){
    int count;
    int res=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=-1){
            count=0;
            int start = nums[i];
            while(nums[start]!=-1){
                int temp=start;
                start=nums[start];
                count++;
                nums[temp]=-1;
            }
            res=max(res,count);
        }
    }
    return res;
}