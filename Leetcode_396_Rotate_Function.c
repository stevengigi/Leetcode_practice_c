#include<stdio.h>
#include<stdlib.h>
//  [a0 a1 a2 a3]
// SIZE:4
// F(0)= 0*a0+1*a1+2*a2+3*a3
// F(1)= 0*a1+1*a2+2*a3+3*a4
// F(1)-F(0)=-(a0+a1+a2+a3)+4*a0
// so F(1)=F(0)-(a0+a1+a2+a3)+4*a0
// F(i)=F(i-1)-sum(arr)+size*a(i-1)
int max(int a,int b){
    return (a>b)?a:b;
}

int maxRotateFunction(int* nums, int numsSize){
    if(numsSize==1){
        return 0;
    }
    int sum=0;
    int f1=0;
    for(int i=0;i<numsSize;i++){
        f1+=i*nums[i];
        sum+=nums[i];
    }
    int res=f1;
    for(int i=1;i<numsSize;i++){
        f1=f1-1*sum+numsSize*nums[i-1];
        res=max(res,f1);
    }
    return res;
}