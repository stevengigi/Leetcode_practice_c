#define e 1000000007
int numTilings(int n){
    long *dp=(long*)malloc(sizeof(long)*1001);
    dp[0]=1;
    dp[1]=1; // |
    dp[2]=2;//  ||  =
    dp[3]=5; // |||  =|  |=  「」  ﹄﹃ ={dp[2]+{|}  ,  dp[1]+{=}  , dp[0]+{「」  ﹄﹃}}
    // dp[4] =11;
    //dp[4] = dp[3]+{|} , dp[2]+{=} , dp[1] + {﹄﹃  「」} , dp[0]+{『-﹃ 、﹄-』}
    //dp[n]=dp[n-1]+dp[n-2]+2*(dp[n-3]+...dp[0]);
    // dp[n-1]=dp[n-2]+dp[n-3]+2*(dp[n-4]+..dp[0]);
    // dp[n]-dp[n-1]=dp[n-1]+dp[n-3];
    // dp[n]=2*dp[n-1]+dp[n-3];
    int temp;

    if(n<=3){
        temp=dp[n];
    }else{
        for(int i=4;i<=n;i++){
            dp[i]=(2*dp[i-1]+dp[i-3])%e;
        }
        temp=dp[n];
    }
    free(dp);
    return temp;
}