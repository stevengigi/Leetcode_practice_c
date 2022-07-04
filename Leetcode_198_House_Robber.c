#include<stdio.h>
#include<stdlib.h>

int max(int a ,int b){
    return (a>b)? a : b;
}

int rob(int* nums, int numsSize){
    if(numsSize==1){
        return nums[0];
    }else if(numsSize==2){
        return max(nums[0],nums[1]);
    }
    int *m=(int*)calloc(numsSize,sizeof(int));
    m[0]=nums[0];
    m[1]=nums[1];
    m[2]=nums[2]+nums[0];
    for(int i=3;i<numsSize;i++){
        m[i]=max(m[i-2],m[i-3])+nums[i];
    }
    return max(m[numsSize-1],m[numsSize-2]);
}

int rob2(int *nums,int numsSize){
    int *dp=(int*)calloc(numsSize,sizeof(int));
    dp[0]=nums[0];
    dp[1]=nums[1];
    for(int i=2;i<numsSize;i++){
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[numsSize-1];
}
int main(){
    int nums[10]={1,2,3,4,5,5,4,3,2,1};
    printf("rob1 money : %d\n",rob(nums,sizeof(nums)/sizeof(int)));
    printf("rob2 money : %d\n",rob2(nums,sizeof(nums)/sizeof(int)));
}