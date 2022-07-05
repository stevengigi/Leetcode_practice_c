#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPerfectSquare(int num){
    // 2^31 -1 = 2147483647
    // sqrt(2147483647)=46340.949219
    int right =46340;
    int left=1;
    int m;
    int ans;
    while(left <= right){
        m=(right-left)/2+left;
        ans=m*m;
        if(ans==num){
            return true;
        }else if(ans<num){
            left=m+1;
        }else {
            right=m-1;
        }
    }
    return false;
}

int main(){
    printf("isPerfectSquare(15): %d \n",isPerfectSquare(15));
    printf("isPerfectSquare(16): %d \n",isPerfectSquare(16));
}