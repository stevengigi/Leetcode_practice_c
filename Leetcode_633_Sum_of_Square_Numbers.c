#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

bool judgeSquareSum(int c){
    if(c==1 || c==0){
        return true;
    }
    long end=(sqrt(c));
    long start=0;
    long sum;
    while(start<=end){
        sum=start*start+end*end;
        if(sum==c){
            return true;
        }else if(sum>c){
            end--;
        }else{
            start++;
        }
    }
    return false;
}

int main(){
    printf("%d",judgeSquareSum(100));
}