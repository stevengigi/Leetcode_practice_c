#include<stdio.h>
#include<stdlib.h>
int Tribonacci(int);
int main(){
    printf("Tribonacci (5) : %d\n",Tribonacci(5));
}

int Tribonacci(int n){
    int array[3];
    array[0]=0;
    array[1]=1;
    array[2]=1;
    for(int i=3;i<=n;i++){
        array[i%3]=array[0]+array[1]+array[2];
    }
    return array[n%3];
}