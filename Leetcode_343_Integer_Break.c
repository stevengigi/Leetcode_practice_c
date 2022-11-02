int max(int a,int b){
    return (a>b)?a:b;
}
int integerBreak(int n){
    int *dp=(int*)calloc((n+1),sizeof(int));
    dp[1]=1;
    for(int i=2;i<n+1;i++){
        if(i==n) dp[i]=0;
        else dp[i]=i;
        for(int j=1;j<i;j++){
            int val=dp[j]*dp[i-j];
            dp[i]=max(dp[i],val);
        }
    }
    int ans=dp[n];
    free(dp);
    return ans;
}
// ex  n=5
//  1  2                3               4                     5
//  1  2=max(2,1+1)  3=max(1+2,3)       4=max(2+2,4,1+3)       6