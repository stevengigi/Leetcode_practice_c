#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


bool isMonotonic(int* nums, int numsSize){
//     flag=1 increasing
//     flag=0 decreasing
    int flag=-1;
    if(numsSize<=2){
        return true;
    }
    int top=0;
    for(int i=1;i<numsSize;i++){
        if(nums[i]==nums[top]){
            continue;
        }
        if(nums[i]>nums[top]){
            if(flag==0){
                return false;
            }
            flag=1;
            top=i;
        }
        if(nums[i]<nums[top]){
            if(flag==1){
                return false;
            }
            flag=0;
            top=i;
        }
    }
    return true;
}

int main(){
    int arr[5]={1,2,2,3,3};
    int arr2[5]={1,2,2,3,1};
    printf("ans : %d\n",isMonotonic(arr,sizeof(arr)/sizeof(int)));
    printf("ans : %d\n",isMonotonic(arr2,sizeof(arr2)/sizeof(int)));
}