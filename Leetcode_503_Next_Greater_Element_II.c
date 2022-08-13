#include<stdio.h>
#include<stdlib.h>

int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    int *res=(int*)calloc(numsSize,sizeof(int));
    int *stack=(int*)calloc(numsSize,sizeof(int));
    *returnSize=numsSize;
    int top=-1;

    for(int i=numsSize*2-1;i>=0;--i){
        while(top!=-1 && stack[top] <= nums[i%numsSize]){
            --top;
        }
        if(top==-1){
            res[i%numsSize]=-1;
        }else{
            res[i%numsSize]=stack[top];
        }
        ++top;
        stack[top]=nums[i%numsSize];

    }
    free(stack);

    return res;
}

int main(){
    int nums[5]={5,4,3,2,1};
    int size=0;
    int *p=nextGreaterElements(nums,sizeof(nums)/sizeof(int),&size);
    for(int i=0;i<size;i++){
        printf(" %d ",p[i]);
    }
}