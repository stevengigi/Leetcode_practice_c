int min(int a,int b){
    return (a<b)?a:b;
}
int minDistance(char * word1, char * word2){
    int len1=strlen(word1);
    int len2=strlen(word2);
    int **dp=(int**)malloc(sizeof(int*)*(len1+1));
    for(int i=0;i<len1+1;i++){
        dp[i]=(int*)calloc(len2+1,sizeof(int));
    }

    for(int row=0;row<len1+1;row++){

        for(int col=0;col<len2+1;col++){
            if(row==0 || col==0){
              dp[row][col]=col+row;
            }else{

                if(word1[row-1]==word2[col-1]){
                    dp[row][col]=dp[row-1][col-1];
                }else{
                    // printf("aaaa/\n");
                    dp[row][col]=min(dp[row-1][col],dp[row][col-1])+1;
                }

            }
            // printf("row : %d | col : %d | val : %d\n",row,col,dp[row][col]);
        }
    }
    return dp[len1][len2];
}


