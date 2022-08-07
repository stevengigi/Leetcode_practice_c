#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return (a>b)?a:b;
}

int totalSteps(int* nums, int numsSize){
    int *stack=(int*)calloc(numsSize,sizeof(int));
    int *dp=(int*)calloc(numsSize,sizeof(int));
    int top=-1;
    int res=0;
    for(int i=numsSize-1;i>=0;i--){
        while(top>=0 && nums[i]>nums[stack[top]]){
            dp[i]=max(++dp[i],dp[stack[top--]]);
            res=max(res,dp[i]);
        }
        stack[++top]=i;
    }
    return res;
}

int main(){
    int nums[5]={5,2,4,1,3};
    printf(" %d ",totalSteps(nums,sizeof(nums)/sizeof(nums[0])));
}

