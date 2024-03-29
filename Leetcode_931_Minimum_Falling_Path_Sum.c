int min(int a,int b){
    return (a>b)?b:a;
}

int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize){
    int dp[matrixSize][*matrixColSize+2];

    for(int i=0;i<matrixSize;i++){
        dp[i][0]=INT_MAX;
        dp[i][*matrixColSize+1]=INT_MAX;
    }

    for(int i=1;i<*matrixColSize+1;i++){
        dp[0][i]=matrix[0][i-1];
    }

    for(int i=1;i<matrixSize;i++){
        for(int j=1;j<*matrixColSize+1;j++){
            int mintemp=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i-1][j+1]);
            dp[i][j]=matrix[i][j-1]+mintemp;
        }
    }
    // for(int i=0;i<matrixSize;i++){
    //     for(int j=0;j<*matrixColSize+2;j++){
    //         printf(" %d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }
    int res=dp[matrixSize-1][1];
    for(int j=1;j<*matrixColSize+1;j++){
        res=min(res,dp[matrixSize-1][j]);
    }
    return res;
}