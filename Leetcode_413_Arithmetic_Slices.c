#include<stdio.h>
#include<stdlib.h>

int numberOfArithmeticSlices(int* nums, int numsSize){
    if(numsSize<3){
        return 0;
    }
    int *dp=(int*)calloc(numsSize,sizeof(int));
    int cnt=0;
    if(nums[2]-nums[1]==nums[1]-nums[0]){
        dp[2]=1;
    }
    cnt=dp[2];
    for(int i=3;i<numsSize;i++){
        if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
            dp[i]=dp[i-1]+1;
        }
        cnt+=dp[i];
    }
    free(dp);
    return cnt;

}

int main(){
    int nums[5]={1,2,3,4,5};
    printf("%d",numberOfArithmeticSlices(nums,sizeof(nums)/sizeof(nums[0])));
}