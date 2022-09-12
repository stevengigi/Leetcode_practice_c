

int sumOfUnique(int* nums, int numsSize){
    int table[101]={0};
    int res=0;
    for(int i=0;i<numsSize;i++){
        if(table[nums[i]]==0){
            res+=nums[i];
            table[nums[i]]++;
        }
        else if(table[nums[i]]==1){
            res-=nums[i];
            table[nums[i]]++;
        }
    }
    return res;
}