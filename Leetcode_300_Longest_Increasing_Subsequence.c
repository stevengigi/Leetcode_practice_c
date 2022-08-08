#include<stdio.h>
#include<stdlib.h>
// reference : https://www.youtube.com/watch?v=cjWnW0hdF1Y
int max(int a,int b){
    return (a>b)?a:b;
}

int lengthOfLIS(int* nums, int numsSize){
    int *dp=(int*)calloc(numsSize,sizeof(int));
    int res=INT_MIN;
    for(int i=numsSize-1;i>=0;i--){
        dp[i]=1;
        for(int j=i+1;j<numsSize;j++){
            if(nums[j]>nums[i]){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        res=max(res,dp[i]);
    }
    free(dp);
    return res;
}

int main(){
    int nums[4]={1,2,4,3};
    printf("%d",lengthOfLIS(nums,sizeof(nums)/sizeof(nums[0])));
}