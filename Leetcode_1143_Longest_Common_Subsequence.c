int max(int a,int b){
    return (a>=b)?a:b;
}
int longestCommonSubsequence(char * text1, char * text2){
    int len1=strlen(text1);
    int len2=strlen(text2);

    int **dp=(int**)malloc(sizeof(int*)*2);
    for(int i=0;i<2;i++){
        dp[i]=(int*)calloc(len2+1,sizeof(int));
    }
    for(int i=1;i<len1+1;i++){
        for(int j=1;j<len2+1;j++){

            if(text1[i-1]==text2[j-1]){
                dp[i%2][j]=1+dp[(i-1)%2][j-1];
            }
            else{
                dp[i%2][j]=max( dp[i%2][j-1] , dp[(i-1)%2][j] );
            }
        }
    }
    return dp[len1%2][len2];
}