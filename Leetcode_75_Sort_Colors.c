#include<stdio.h>
#include<stdlib.h>

void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void sortColors(int* nums, int numsSize){
    int start=0;
    int res=0;
    int end=numsSize-1;
    while(res<=end){
        if(nums[res]==0){
            swap(&nums[res],&nums[start]);
            start++;
            res++;
        }else if(nums[res]==2){
            swap(&nums[res],&nums[end]);
            end--;
        }else{
            res++;
        }
    }
}

int main(){
    int nums[10]={0,1,1,2,2,2,1,1,0,0};
    sortColors(nums,sizeof(nums)/sizeof(int));
    for(int i=0;i<sizeof(nums)/sizeof(int);i++){
        printf(" %d ",nums[i]);
    }
}