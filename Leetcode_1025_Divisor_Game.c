#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool divisorGame(int n){
    return n%2==0;
}
int main(){
    printf("win possibility : %d\n",divisorGame(10));
    printf("win possibility : %d\n",divisorGame(5));
}