#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return (a>b)?a:b;
}
//Greedy
int jump(int* nums, int numsSize){
    int maxposition=0;
    int end=0;
    int step=0;
    for(int i=0;i<numsSize-1;i++){
        maxposition=max(maxposition,nums[i]+i);
        if(i==end){
            end=maxposition;
            step++;
        }
    }
    return step;
}
//BFS
int jump2(int* nums, int numsSize){
    int r=0;
    int l=0;
    int step=0;
    int far=0;
    while(r<numsSize-1){
        far=0;
        for(int i=l;i<=r;i++){
            far=max(far,nums[l]+l);
        }
        l=r+1;
        r=far;
        step++;
    }
    return step;
}


int main(){
    int nums[6]={1,1,1,1,1,1};
    printf("%d\n",jump(nums,sizeof(nums)/sizeof(int)));
    printf("%d\n",jump2(nums,sizeof(nums)/sizeof(int)));
}