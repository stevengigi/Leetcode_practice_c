#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool increasingTriplet(int* nums, int numsSize){
    if(numsSize < 3) return false;
    int small=INT_MAX;
    int middle=INT_MAX;
    for(int i=0;i<numsSize;i++){
        if(nums[i]<=small){
            small=nums[i];
        }else if(nums[i] <= middle){
            middle=nums[i];
        }else{
            return true;
        }
    }
    return false;
}
int main(){
    int nums[4]={2,5,4,6};
    printf("%d",increasingTriplet(nums,sizeof(nums)/sizeof(int)));
}