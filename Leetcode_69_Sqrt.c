#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int mySqrt(int x){
    int left=1;
    int right=46341;
    int mid;
    if(x==0){
        return 0;
    }
    while(true){
        mid=(left+right)/2;
        if(mid*mid==x){
            return mid;
        }
        if(left+1==right){
            return left;
        }
        if(mid*mid < x){
            left=mid;
        }else{
            right=mid;
        }

    }
}

int main(){
    printf(" %d ",mySqrt(10));
}