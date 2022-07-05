#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int searchInsert(int* nums, int numsSize, int target){
    int left=0;
    int right=numsSize-1;
    int m;
    while(true){
        if(right<left){
            return left;
        }
        m=(right-left)/2+left;
        if(nums[m]>target){
            right=m-1;
        }else if(nums[m]<target){
            left=m+1;
        }else if(nums[m]==target){
            return m;
        }

    }
}

int main(){
    int nums[4]={1,3,5,6};
    int target=2;
    printf("position : %d\n",searchInsert(nums,sizeof(nums)/sizeof(int),target));
}