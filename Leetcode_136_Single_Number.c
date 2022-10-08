#include<stdio.h>
#include<stdlib.h>
int singleNumber(int* nums, int numsSize){
    int ans=0;
    for(int i=0;i<numsSize;i++){
        ans ^=nums[i];
    }
    return ans;
}

int main(){
    int nums[5]={2,2,1,1,5};
    printf("%d",singleNumber(nums,sizeof(nums)/sizeof(int)));
}