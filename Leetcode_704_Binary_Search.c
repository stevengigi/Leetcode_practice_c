#include<stdio.h>
#include<stdlib.h>

int binarysearch(int *nums, int numsSize,int target){
    int right=numsSize-1;
    int left=0;
    int mid;
    while(left<=right){
        mid=(right+left)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(target < nums[right]){
            right--;
        }
        if(target > nums[left]){
            left++;
        }
    }
    return -1;
}

int main(){
    int nums[10]={1,3,4,6,7,8,9,10,15,20};
    printf("binarysearch(10) : %d \n",binarysearch(nums,sizeof(nums)/sizeof(int),10));
}