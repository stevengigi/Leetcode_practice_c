

int removeDuplicates(int* nums, int numsSize){
    int index=0;
    for(int i=0;i<numsSize;i++){
        if(index<2 || nums[i]>nums[index-2]){
            nums[index++]=nums[i];
        }
    }
    return index;
}