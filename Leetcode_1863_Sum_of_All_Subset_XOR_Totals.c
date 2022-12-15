void backtrack(int *nums,int numsSize,int index,int target,int *res){
    if(index==numsSize){
        return;
    }
    for(int i=index;i<numsSize;i++){
        target^=nums[i];
        (*res)+=target;
        backtrack(nums,numsSize,i+1,target,res);
        target^=nums[i];
    }
}

int subsetXORSum(int* nums, int numsSize){
    int res=0;
    for(int i=0;i<numsSize;i++){
        res+=nums[i];
        backtrack(nums,numsSize,i+1,nums[i],&res);
    }
    return res;
}