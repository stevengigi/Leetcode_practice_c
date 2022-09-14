int min(int a,int b){
    return a>b?b:a;
}

int mostFrequentEven(int* nums, int numsSize){
    int table[50000]={0};
    int res=INT_MAX;
    int most=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]%2==0){
            table[nums[i]/2]++;
            if(most <= table[nums[i]/2]){
                res=(most==table[nums[i]/2])?min(res,nums[i]):nums[i];
                most=table[nums[i]/2];
            }
        }
    }
    return res==INT_MAX ? -1:res;
}