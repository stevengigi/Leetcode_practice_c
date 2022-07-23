#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct stack{
    int currentmin;
    int num;
};
int min(int a,int b){
    return (a>b)?b:a;
}

bool find132pattern(int* nums, int numsSize){
    struct stack stack[numsSize];
    stack[0].num=nums[0];
    // stack[0].currentmin=nums[0];
    int amin=nums[0];
    int top=0;
    for(int i=1;i<numsSize;i++){

        while(top!=-1 && nums[i]>=stack[top].num){
            top--;
        }
        if(top!=-1  &&  nums[i] > stack[top].currentmin){
            return true;
        }
        top++;
        stack[top].num=nums[i];
        stack[top].currentmin=amin;
        amin=min(amin,nums[i]);
    }
    return false;
}
int main(){
    int nums[4]={3,1,4,2};
    printf("find132pattern : %d ",find132pattern(nums,sizeof(nums)/sizeof(int)));
}