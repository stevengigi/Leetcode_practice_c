int longestSubarray(int* nums, int numsSize){
    int max=-1;
    int res=0;
    for(int i=0;i<numsSize;i++){
        max=max>nums[i]?max:nums[i];
    }
    int length=0;
    for(int i=0;i<numsSize;i++){
        if(max==nums[i]) length++;
        else length=0;
        res=res>length?res:length;
    }
    return res;
}