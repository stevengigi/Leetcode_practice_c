#include<stdio.h>
#include<stdlib.h>



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize){
    *returnSize=0;
    int cand1=INT_MIN;
    int vote1=0;
    int cand2=INT_MAX;
    int vote2=0;
    for(int i=0;i<numsSize;i++){
        if(vote1>=0 && nums[i]==cand1){
            vote1++;
        }else if(vote2>=0 && nums[i]==cand2){
            vote2++;
        }else if(vote1==0 && cand1!=nums[i]){
            cand1=nums[i];
            vote1++;
        }else if(vote2==0 && cand2!=nums[i]){
            cand2=nums[i];
            vote2++;
        }else{
            vote1--;
            vote2--;
        }
    }
    int cnt1=0;
    int cnt2=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==cand1){
            cnt1++;
        }
        if(nums[i]==cand2){
            cnt2++;
        }
    }
    int *res=(int*)malloc(sizeof(int)*2);
    if(cnt1>numsSize/3){
        *returnSize=*returnSize+1;
        res[*returnSize-1]=cand1;
    }
    if(cnt2>numsSize/3){
        *returnSize=*returnSize+1;
         res[*returnSize-1]=cand2;
    }

    return res;
}

int main(){
    int nums[10]={1,2,3,1,2,3,1,1,2,2};
    int returnsize=0;
    int *p=majorityElement(nums,sizeof(nums)/sizeof(int),&returnsize);
    for(int i=0;i<returnsize;i++){
        printf(" %d ",p[i]);
    }
}