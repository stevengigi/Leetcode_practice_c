#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPowerOfFour(int n){
    return n>0 && (n&(n-1)) == 0 && (n & 0x55555555) != 0;
}

int main(){
    int a=15;
    printf("%d",isPowerOfFour(a));
}

