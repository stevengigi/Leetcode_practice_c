#include<stdio.h>
#include<stdlib.h>
int fib(int);
int fib2(int);
int main(){
    printf("Fibonacci_number (5) : %d\n",fib(5));
    printf("Fibonacci_number (5) : %d\n",fib2(5));
}

/* DP */
int fib(int n){
    if(n==1 || n==2){
        return 1;
    }else{
        int array[2];
        int i;
        array[0]=0;
        array[1]=1;
        for(i=2;i<=n;i++){
            array[i%2]=array[0]+array[1];

        }
        return array[n%2];
    }
}
/*  Recursive  */
int fib2(int n){
    if(n==1 ||n==2){
        return 1;
    }else{
        return fib2(n-1)+fib2(n-2);
    }
}