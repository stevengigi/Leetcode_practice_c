int numDecodings(char *s)
{
    if (s[0] == '0')
        return 0;
    int sn = strlen(s);
    int *dp = (int *)calloc(sn+1,sizeof(int));
    dp[0] = 1;
    dp[1] =1;
    for (int i=1;i<sn;i++)
    {
        if (s[i]>'0')
            dp[i+1] += dp[i];
        if (s[i-1]=='1'||(s[i-1]=='2' && s[i]<='6'))
            dp[i+1]+=dp[i-1];
        printf("%d: %d\n",i,dp[i+1]);
    }
    return dp[sn];
}

