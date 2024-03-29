int min(int a,int b){
    return (a>b)?b:a;
}

int numSquares(int n){
    int *dp=(int*)malloc((n+1)*sizeof(int));
    for(int i=0;i<n+1;i++){
        dp[i]=n;
    }
    dp[0]=0;
    for(int i=1;i<n+1;i++){
        for(int s=1;s<i+1;s++){
            int square = s*s;
            if(i-square < 0){
                break;
            }
            dp[i]=min(dp[i],1+dp[i-square]);
            // printf("s: %d |target : %d | dp[target] : %d\n",s,i,dp[i-square]);
        }
    }
    return dp[n];
}