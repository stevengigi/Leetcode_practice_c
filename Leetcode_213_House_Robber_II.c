#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return (a>b)? a : b;
}

int robber(int *nums,int start,int end,int size){
    int *cache=(int*)calloc(size,sizeof(int));
    cache[start]=nums[start];
    cache[start+1]=nums[start];
    for(int i=start+2;i<=end;i++){
        cache[i]=max(nums[i]+cache[i-2],cache[i-1]);
    }
    int ans=cache[end];
    free(cache);
    return ans;
}

int rob(int* nums, int numsSize){
    if(numsSize==0){
        return 0;
    }else if(numsSize==1){
        return nums[0];
    }else if(numsSize==2){
        return max(nums[0],nums[1]);
    }else if(numsSize==3){
        return max(max(nums[0],nums[1]),nums[2]);
    }else{
        return max(robber(nums,2,numsSize-1,numsSize),max(robber(nums,0,numsSize-2,numsSize),robber(nums,1,numsSize-1,numsSize)));

    }
}

int main(){
    int nums[10]={1,2,3,4,5,1,2,3,4,5};
    printf("rob money : %d",rob(nums,sizeof(nums)/sizeof(int)));
}