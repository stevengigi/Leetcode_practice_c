#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool isPalindrome(int x){
    if(x<0){
        return false;
    }
    int xx=x;
    long int res=0;
    while(x!=0){
        int temp=x%10;
        x/=10;
        res=res*10+temp;
    }
    return (res!=xx)?false:true;
}

int main(){
    int x=121;
    printf("ans : %d",isPalindrome(x));
}