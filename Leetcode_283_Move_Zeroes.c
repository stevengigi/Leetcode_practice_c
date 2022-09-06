void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void moveZeroes(int* nums, int numsSize){
    for(int lastnonzero=0,curr=0;curr<numsSize;curr++){
        if(nums[curr]!=0){
            swap(&nums[lastnonzero++],&nums[curr]);
        }
    }
}