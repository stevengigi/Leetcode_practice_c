int min(int a,int b){
    return (a>b)?b:a;
}

int min3(int a,int b,int c){
    return min(min(a,b),c);
}

int max(int a,int b){
    return (a>b)?a:b;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    int row=matrixSize;
    int col=*matrixColSize;
    int **dp=(int**)malloc((row+1)*sizeof(int*));
    for(int i=0;i<=row;i++){
        dp[i]=(int *)calloc(col+1,sizeof(int));
    }
    int res=0;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(matrix[i-1][j-1]=='1'){
                dp[i][j]=min3(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1;
                res=max(res,dp[i][j]);
            }

        }
    }
    return res*res;
}