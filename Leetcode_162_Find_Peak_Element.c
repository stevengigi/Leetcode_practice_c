#include<stdio.h>

int findPeakElement(int* nums, int numsSize){
    // if(numsSize==1){
    //     return -1;
    // }
    int low=0;
    int high=numsSize-1;
    int mid;
    while(low<high){
        mid=(high-low)/2+low;
        if(nums[mid]>nums[mid+1]){
            high=mid;
        }else{
            low=mid+1;
        }
    }
    return low;
}
int main(){
    int nums[4] = {1,2,3,1};
    printf(" %d ",findPeakElement(nums,sizeof(nums)/sizeof(int)));
}