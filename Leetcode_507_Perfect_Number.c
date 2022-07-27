#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



bool checkPerfectNumber(int num){
    return (num==6 || num==28 || num==496 ||num==8128 ||num==33550336)?true:false;
}

int main(){
    printf("ans : %d\n",checkPerfectNumber(28));
    printf("ans : %d\n",checkPerfectNumber(29));
}