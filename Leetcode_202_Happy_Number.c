#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int getsum(int n){
    int temp;
    int sum=0;
    while(n!=0){
        temp=n%10;
        sum+=temp*temp;
        n/=10;
    }
    return sum;
}
bool isHappy(int n){
    if(n==1){
        return true;
    }
    int slow=n;
    int fast=n;
    while(true){
        slow=getsum(slow);
        fast=getsum(fast);
        fast=getsum(fast);
        if(slow==1 || fast==1){
            return true;
        }
        if(slow==fast){
            return false;
        }

    }
}

int main(){
    printf("%d\n",isHappy(11));
}