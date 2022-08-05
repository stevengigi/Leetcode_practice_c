#include<stdio.h>
#include<stdlib.h>

int combinationSum4(int* nums, int numsSize, int target){
    unsigned int *dp=(unsigned int*)malloc((target+1)*sizeof(unsigned int));
    dp[0]=1;
    for(int i=1;i<=target;i++){
        dp[i]=0;
        for(int j=0;j<numsSize;j++){
            if(i>=nums[j]){
                dp[i]=dp[i]+dp[i-nums[j]];
            }
        }
    }
    unsigned int res=dp[target];
    free(dp);
    return res;
}

int main(){
    int nums[3]={1,2,3};
    int target=4;
    printf("%d",combinationSum4(nums,3,target));
}