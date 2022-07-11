#include<stdio.h>
#include<stdlib.h>

/*int* runningSum(int* nums, int numsSize, int* returnSize){
    int *res=(int*)malloc(sizeof(int)*numsSize);
    res[0]=nums[0];
    for(int i=1;i<numsSize;i++){
        res[i]=nums[i]+res[i-1];
    }
    *returnSize=numsSize;
    return res;
}*/
int* runningSum(int* nums, int numsSize, int* returnSize){
    int *res=(int*)calloc(numsSize,sizeof(int));
    int temp;
    // res[0]=nums[0];
    for(int i=0;i<numsSize;i++){
        temp+=nums[i];
        res[i]+=temp;
    }
    *returnSize=numsSize;
    return res;
}
int main(){
    int nums[6]={1,2,3,4,5,6};
    int returnsize;
    int *p=runningSum(nums,sizeof(nums)/sizeof(int),&returnsize);
    printf("returnsize : %d\n",returnsize);
    for(int i=0;i<sizeof(nums)/sizeof(int);i++){
        printf(" %d ",p[i]);
    }
}