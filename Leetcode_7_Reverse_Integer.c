#include<stdio.h>
#include<stdlib.h>
int reverse(int x){
    long long res=0;
    while(x!=0){
        int temp=x%10;
        x=x/10;
        res=res*10+temp;
    }
    if(res > INT_MAX )return 0;
    if(res<INT_MIN) return 0;
    return res;
}

int main(){
    int test=-54678;
    printf("%d",reverse(test));
}