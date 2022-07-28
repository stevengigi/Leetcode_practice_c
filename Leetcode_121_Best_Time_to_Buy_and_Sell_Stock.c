#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return (a>b)?a:b;
}

int maxProfit(int* prices, int pricesSize){
    int left=0;
    int res=0;;
    for(int i=1;i<pricesSize;i++){
       if(prices[left]>prices[i]){
           left=i;
           continue;
       }
        res=max(res,prices[i]-prices[left]);
    }
    return res;
}
int main(){
    int prices[7]={7,1,5,8,0,9,5};
    printf("%d",maxProfit(prices,sizeof(prices)/sizeof(int)));
}