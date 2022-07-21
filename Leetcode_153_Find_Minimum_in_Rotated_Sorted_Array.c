#include<stdio.h>
#include<stdlib.h>
//已知道是rotated
int min(int a,int b){
    return (a>b)?b:a;
}
int findMin(int* nums, int numsSize){
    int left=0;
    int right=numsSize-1;
    int mid;
    if(numsSize==1){
        return nums[0];
    }
    if(numsSize==2){
        return min(nums[0],nums[1]);
    }
//   3 4 5 0 1 2
//   L   ^     R
//         L ^ R
//         L R
//
    while(left<right){
        mid=(right-left)/2+left;
        if(nums[left]<nums[right]){
            return nums[left];
        }
        if(nums[mid]>=nums[left]){
            left=mid+1;
        }else{
            right=mid;
        }
    }
    return nums[left];
}

int main(){
    int nums[5]= {3,4,5,1,2};
    printf("%d\n",findMin(nums,sizeof(nums)/sizeof(int)));
}