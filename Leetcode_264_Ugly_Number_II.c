int min(int a,int b){
    return (a>b)?b:a;
}

int nthUglyNumber(int n){
    if(n==1) return true;
    int dp[n+1];
    dp[1]=1;
    int index2=1,index3=1,index5=1;

    for(int i=2;i<=n;i++){
        dp[i]=min(min(dp[index2]*2,dp[index3]*3),dp[index5]*5);
        if(dp[i]==2*dp[index2]) index2++;
        if(dp[i]==3*dp[index3]) index3++;
        if(dp[i]==5*dp[index5]) index5++;
    }


    return dp[n];
}