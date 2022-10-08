#include<stdio.h>
#include<stdlib.h>

int singleNumber(int* nums, int numsSize){
    int one=0, two=0;
    for(int i=0;i<numsSize;i++){
        one = (one^nums[i]) & ~two;
        two = (two^nums[i]) & ~one;
        printf("one : %d  | two : %d | nums[i] : %d\n",one,two,nums[i]);
    }
    return one;
}

int main(){
    int nums[7]={1,1,1,2,2,2,3};
    printf("%d",singleNumber(nums,sizeof(nums)/sizeof(int)));
}