int min(int a,int b){
    return (a>b)?b:a;
}

int coinChange(int* coins, int coinsSize, int amount){
    int *dp=(int*)calloc(amount+1,sizeof(int));
    for(int i=1;i<amount+1;i++){
        dp[i]=amount+1;
    }

    for(int i=1;i<=amount;i++){
        for(int j=0;j<coinsSize;j++){
            if(coins[j]<=i){
                dp[i]=min(dp[i],dp[i-coins[j]]+1);

            }

        }
    }
    int index=dp[amount];
    free(dp);
    return index > amount ? -1:index;
}