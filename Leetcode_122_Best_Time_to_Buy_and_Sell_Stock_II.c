#include<stdio.h>
#include<stdlib.h>
int maxProfit(int* prices, int pricesSize){
    int profit=0;
    for(int i=1;i<pricesSize;i++){
        if(prices[i]>prices[i-1])
            profit+=prices[i]-prices[i-1];
    }
    return profit;
}

int main(){
    int prices[7]={7,1,5,8,0,9,5};
    printf("%d",maxProfit(prices,sizeof(prices)/sizeof(int)));
}