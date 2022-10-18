int max(int a,int b){
    return (a>b)?a:b;
}

int maxProfit(int* prices, int pricesSize, int fee){
    int cash=0;
    int hold=-1*prices[0];
    for(int i=0;i<pricesSize;i++){
        cash = max(cash,prices[i]+hold-fee);
        hold=max(hold,cash-prices[i]);
    }
    return cash;
}