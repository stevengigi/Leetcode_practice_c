#include<stdio.h>
#include<stdlib.h>

//Brutal force
int cmp ( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}

int specialArray(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    for(int i=1;i<=numsSize;i++){
        if(i==numsSize){
            if(nums[0]>=i){
                return i;
            }
        }
        if(nums[numsSize-i]>=i && nums[numsSize-i-1]<i){
            return i;
        }
    }
    return -1;
}

int main(){
    int nums[5]={3,3,0,0,4};
    printf(" %d\n",specialArray(nums,sizeof(nums)/sizeof(int)));
}