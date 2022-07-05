#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int pick =6;
int guess(int num){
    if(num==pick){
        return 0;
    }else if(num<pick){
        return 1;
    }else{
        return -1;
    }
}

int guessNumber(int n){
    int right=n;
    int left=1;
    int m;
    int res;
    while(true){
        m=(right-left)/2+left;
        res=guess(m);
        if(res==0){
           return m;
        }else if(res==1){
            left=m+1;
        }else if(res==-1){
            right=m-1;
        }
    }
}

int main(){
    printf(" %d \n",guessNumber(10));
}