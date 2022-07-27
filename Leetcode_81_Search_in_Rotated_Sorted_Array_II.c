#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool search(int* nums, int numsSize, int target){
    int left=0;
    int right=numsSize-1;
    int mid;
    while(left<=right){
        mid=(right-left)/2+left;
        if(nums[mid]==target){
            return true;
        }
        if(nums[right]==nums[mid] && nums[left]==nums[mid]){
            right--;
            left++;
            printf("left :%d right : %d\n",left,right);
            continue;
        }
        if(nums[left]<=nums[mid]){
            if(nums[left]<=target && nums[mid]>=target){
                right=mid-1;
                printf("go\n");
                printf("right : %d\n",right);
            }else{
                left=mid+1;
            }
        }else{
            if(nums[right]>=target && nums[mid]<=target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
    }
    return false;
}

int main(){
    int nums[5]={1,0,1,1,1};
    printf("%d\n",search(nums,sizeof(nums)/sizeof(int),0));
}