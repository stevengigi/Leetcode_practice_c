#include<stdio.h>
#include<stdlib.h>

int majorityElement(int* nums, int numsSize){
//     Boyer–Moore majority vote algorithm
    int vote=1;
    int res=nums[0];
    for(int i=1;i<numsSize;i++){
        if(res==nums[i]){
            vote++;
        }else{
            vote--;
        }
        if(vote==-1){
            res=nums[i];
            vote=1;
        }
    }
    return res;
}

int main(){
    int nums[10]={1,2,3,3,3,3,4,4,3,3};
    printf("%d",majorityElement(nums,10));
}