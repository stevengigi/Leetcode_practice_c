#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// [1,3,-1,-3,5,3,6,7], k = 3
// [1  3  -1] -3  5  3  6  7    => [3(1) -1(2)] tail=(1) head=0  res=[3]
// 1 [3  -1 -3]  5  3  6  7    => [3(1) -1(2) -3(3)] tail=(2) head=0 res=[3 3]
// 1 3  [-1 -3  5]  3  6  7    => [5(4)] tail=(-1) head=0 res=[3 3 5]
// 1 3  -1 [-3  5  3]  6  7    => [5(4) 3(5)] tail=(0) head=0 res=[3 3 5 5]
// 1 3  -1 -3  [5  3  6]  7    => [6(6)] tail=(-1) head=0 res=[3 3 5 5 6]
// 1 3  -1 -3  5  [3  6  7]    => [7(7)] tail=(-1) head=0 res=[3 3 5 5 6 7]

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int res_size=numsSize-k+1;
    int *res=(int*)malloc(sizeof(int)*res_size);
    int *queue=(int*)malloc(sizeof(int)*numsSize);
    memset(queue,0,numsSize);
    int head=0;
    int tail=-1;
    int j=0;
    for(int i=0;i<numsSize;i++){
        while(tail>=head && nums[i]>nums[queue[tail]]){
            tail--;
        }
        queue[++tail]=i;
        if(i-queue[head]+1>k){
            head++;
        }
        if(i-j+1>=k){
            res[j++]=nums[queue[head]];
        }


    }
    *returnSize=j;
    free(queue);
    return res;
}

int main(){
    int nums[6]={1,-1,3,5,2,-5};
    int size;
    int *p=maxSlidingWindow(nums,sizeof(nums)/sizeof(int),3,&size);
    for(int i=0;i<size;i++){
        printf(" %d ",p[i]);
    }
}