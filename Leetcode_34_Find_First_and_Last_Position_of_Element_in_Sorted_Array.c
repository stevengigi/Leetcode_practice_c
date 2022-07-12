#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    *returnSize=2;
    int *res=(int*)malloc(sizeof(int)*2);
    res[0]=-1;
    res[1]=-1;
    if(numsSize==0){
        return  res;
    }
    if(numsSize==1){
        if(nums[0]==target){
            res[0]=0;
            res[1]=0;
            return res;
        }else{
            return res;
        }
    }
    int right=numsSize-1;
    int left=0;
    int mid;

    while(true){
        mid=(right-left)/2+left;
        if(left+1==right && nums[left]!=target && nums[right]!=target){
            return res;
        }
        if(nums[mid]==target){
            right=mid;
            left=mid;
            break;
        }else if(nums[left]==target){
            right=left;
            break;
        }else if(nums[right]==target){
            left=right;
            break;
        }
        if(nums[mid] < target){
            left=mid;
        }else{
            right=mid;
        }
    }

    while(true){
        if(right==numsSize-1){
            res[1]=right;
        }else if(nums[right+1]==target){
            right++;
        }else{
            res[1]=right;
        }
        if(left==0){
            res[0]=left;
        }else if(nums[left-1]==target){
            left--;
        }else{
            res[0]=left;
        }
        if(res[0]!=-1 && res[1]!=-1){
            return res;
        }
    }
}

int main(){
    int nums[6] = {5,7,7,8,8,10};
    int target=6;
    int returnsize;
    int *p;
    p=searchRange(nums,sizeof(nums)/sizeof(int),target,&returnsize);
    for(int i=0;i<returnsize;i++){
        printf(" %d ",p[i]);
    }
}