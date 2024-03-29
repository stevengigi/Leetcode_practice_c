/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int max(int a,int b){
    return a>b?a:b;
}
int min(int a,int b){
    return a>b?b:a;
}
int** matrixBlockSum(int** mat, int matSize, int* matColSize, int k, int* returnSize, int** returnColumnSizes){
    *returnSize=matSize;
    *returnColumnSizes=(int*)malloc(sizeof(int)*(matSize));
    int dp[matSize][*matColSize];
    dp[0][0]=0;
    for(int i=0;i<matSize;i++){
        (*returnColumnSizes)[i]=*matColSize;
    }
    for(int i=0;i<matSize;i++){
        for(int j=0;j<*matColSize;j++){
            if(i==0){
                if(j==0) dp[i][j]=mat[i][j];
                else dp[i][j]=dp[i][j-1]+mat[i][j];
            }
            else if(j==0) dp[i][j]=dp[i-1][j]+mat[i][j];
            else dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mat[i][j];
        }
    }

    // for(int i=0;i<matSize;i++){
    //     for(int j=0;j<*matColSize;j++){
    //         printf(" %d ",dp[i][j]);
    //     }
    //     printf("\n");
    // }

    for(int i=0;i<matSize;i++){
        for(int j=0;j<*matColSize;j++){
            int rowmax=min(i+k,matSize-1);
            int rowmin=max(i-k,0);
            int colmax=min(j+k,*matColSize-1);
            int colmin=max(j-k,0);
            // printf("i : %d | j : %d | colmax : %d | colmin %d | rowmax : %d | rowmin : %d\n",i,j,colmax,colmin,rowmax,rowmin);
            if(colmin==0 && rowmin==0) mat[i][j]=dp[rowmax][colmax];
            else if(rowmin==0) mat[i][j]=dp[rowmax][colmax]-dp[rowmax][colmin-1];
            else if(colmin==0) mat[i][j]=dp[rowmax][colmax]-dp[rowmin-1][colmax];
            else mat[i][j]=dp[rowmax][colmax]-dp[rowmax][colmin-1]-dp[rowmin-1][colmax]+dp[rowmin-1][colmin-1];
        }
    }

    return mat;
}