#include<stdio.h>
#include<stdlib.h>
int max(int a,int b){
    return (a>b)?a:b;
}

int cmp(const void *a,const void *b){
    return *(int*)a -*(int*)b;
}

int maximumProduct(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(int),cmp);
    return max(nums[0]*nums[1]*nums[numsSize-1],nums[numsSize-1]*nums[numsSize-2]*nums[numsSize-3]);
}

int main(){
    int nums[5]={99,100,-1,-3,5};
    printf("%d",maximumProduct(nums,sizeof(nums)/sizeof(int)));
}