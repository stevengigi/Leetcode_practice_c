#include<stdio.h>
#include<stdlib.h>

int pivotIndex(int* nums, int numsSize){
    int left[numsSize];
    left[0]=nums[0];
    int right[numsSize];
    right[numsSize-1]=nums[numsSize-1];
    for(int i=1;i<numsSize;i++){
        left[i]=nums[i]+left[i-1];
        right[numsSize-i-1]=nums[numsSize-i-1]+right[numsSize-i];
    }
    for(int i=0;i<numsSize;i++){
        if(left[i]==right[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int nums[6]={1,7,3,6,5,6};
    printf("ans : %d",pivotIndex(nums,sizeof(nums)/sizeof(int)));
}