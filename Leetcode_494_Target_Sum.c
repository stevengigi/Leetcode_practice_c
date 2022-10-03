int backtrack(int *nums,int numsize,int target,int curr_sum,int pos,int ways){
    if(pos==numsize){
        if(target==curr_sum){
            return ways+1;
        }else{
            return ways;
        }
    }
    else{
        int new_sum=curr_sum-nums[pos];
        int w=backtrack(nums,numsize,target,new_sum,pos+1,ways);
        new_sum=curr_sum+nums[pos];
        w=backtrack(nums,numsize,target,new_sum,pos+1,w);
        return w;
    }
}

int findTargetSumWays(int* nums, int numsSize, int target){
    return backtrack(nums,numsSize,target,0,0,0);
}