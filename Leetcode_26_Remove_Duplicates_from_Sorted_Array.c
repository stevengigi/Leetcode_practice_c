#include<stdio.h>
#include<stdlib.h>

int removeDuplicates(int* nums, int numsSize){
    int i=1;
    for(int j=1;j<numsSize;j++){
        if(nums[j]!=nums[j-1]){
            nums[i]=nums[j];;
            i++;
        }
    }
    return i;
}

int main(){
    int nums[10]={1,2,2,3,4,5,6,6,7,8};
    int i=removeDuplicates(nums,10);
    for(int j=0;j<i;j++){
        printf("%d ",nums[j]);
    }
}