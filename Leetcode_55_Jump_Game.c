#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool canJump(int* nums, int numsSize){
    int goal=numsSize-1;
    for(int i=numsSize-2;i>=0;i--){
        if(i+nums[i]>=goal){
            goal=i;
        }
    }
    return goal==0;
}

int main(){
    int nums[5]={2,3,1,1,4};
    printf(" %d ",canJump(nums,sizeof(nums)/sizeof(int)));
}