char * findDifferentBinaryString(char ** nums, int numsSize){
    for(int i=0;i<numsSize;i++){
        nums[0][i]=nums[i][i]=='0'?'1':'0';
    }
    return nums[0];
}