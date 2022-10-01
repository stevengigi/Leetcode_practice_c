

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    if(obstacleGrid[0][0]==1){
        return 0;
    }
    int *dp=(int*)calloc(*obstacleGridColSize,sizeof(int));
    dp[0]=1;
    for(int i=0;i<obstacleGridSize;i++){
        for(int j=0;j<*obstacleGridColSize;j++){
            if(obstacleGrid[i][j]==1){
                dp[j]=0;
            }else if(j>0){
                dp[j]+=dp[j-1];
            }
        }
    }
    int ans=dp[*obstacleGridColSize-1];
    free(dp);
    return ans;
}