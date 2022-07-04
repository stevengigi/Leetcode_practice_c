#include<stdio.h>
#include<stdlib.h>

int climbStairs(int);
int main(){
    printf("climb(5) : %d\n",climbStairs(5));
}

int climbStairs(int n){
    if(n==1){
        return 1;
    }
    int array[2];
    array[0]=1;
    array[1]=2;
    for(int i=3;i<=n;i++){
        array[(i-1)%2]=array[0]+array[1];
    }
    return array[(n-1)%2];
}