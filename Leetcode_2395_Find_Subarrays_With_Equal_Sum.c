
bool findSubarrays(int* nums, int numsSize){
    for(int i=1;i<numsSize;i++){
        int temp=nums[i]+nums[i-1];
        for(int j=i+1;j<numsSize;j++){
            if(temp==nums[j]+nums[j-1]) return true;
        }
    }
    return false;
}