#include<stdio.h>
#include<stdlib.h>

int findMin(int* nums, int numsSize){
     int start =0;
        int end = numsSize-1;

        if(nums[start] < nums[end])
            return nums[start];

        while(start < end)
        {
            int mid = start + (end-start) /2;

            if(nums[end] < nums[mid])
              start = mid+1;

            else if(nums[end] > nums[mid])
              end = mid;

            else
                end--;
        }
        return nums[end];
}

int main(){
    int nums[5]={3,3,4,1,2};
    printf("%d",findMin(nums,5));
}