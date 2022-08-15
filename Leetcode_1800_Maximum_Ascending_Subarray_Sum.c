#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return (a>b)?a:b;
}

int maxAscendingSum(int* nums, int numsSize){
    // int *stack=(int*)calloc(numsSize,sizeof(int));
    int sum=0;
    int res=INT_MIN;
    for(int i=0;i<numsSize;i++){
        if(i!=0 && nums[i-1]>=nums[i]){
            res=max(res,sum);
            sum=0;
        }
        sum+=nums[i];
    }
    return max(res,sum);
}

int main(){
    int nums[9]={3,6,10,1,8,9,9,8,9};
    printf("%d",maxAscendingSum(nums,sizeof(nums)/sizeof(nums[0])));
}