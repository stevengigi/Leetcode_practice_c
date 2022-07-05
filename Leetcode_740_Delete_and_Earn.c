#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return (a>b)? a : b;
}
int min(int a, int b){
    return (a>b)? b : a;
}


int rob(int *cache,int start,int end){
    int *dp=(int*)calloc(end-start+1,sizeof(int));
    dp[0]=cache[start]*start;
    dp[1]=cache[start+1]*(start+1);
    for(int i=2;i<=end;i++){
        dp[i]=max(cache[start+i]*(start+i)+dp[i-2],dp[i-1]);
    }
    int ans=dp[end];
    free(dp);
    return ans;
}

int deleteAndEarn(int* nums, int numsSize){
    if(numsSize==1){
        return nums[0];
    }
    int *cache=(int*)calloc(10001,sizeof(int));
    int end=0;
    int start=0;
    for(int i=0;i<numsSize;i++){
        cache[nums[i]]++;
        end=max(end,nums[i]);
        start=min(start,nums[i]);
    }
    int ans = rob(cache,start,end);
    free(cache);
    return ans;

}

int main(){
    int nums[6]={2,2,3,3,3,5};
    printf("deleteAndEarn : %d \n",deleteAndEarn(nums,sizeof(nums)/sizeof(int)));
}