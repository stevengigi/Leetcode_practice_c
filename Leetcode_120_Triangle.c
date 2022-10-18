int min(int a,int b){
    return (a<b)?a:b;
}

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    printf("triangleSize : %d |  triangleColSize :%d\n",triangleSize,triangleColSize[triangleSize-1]);
    int *dp=(int*)calloc(triangleColSize[triangleSize-1]+1,sizeof(int));
    for(int i=triangleSize-1;i>=0;i--){
        for(int j=0;j<triangleColSize[i];j++){
            dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
            printf(" %d ",dp[j]);
        }
        printf("\n");
        // for(int i=0;i<)/
    }
    int ans=dp[0];
    free(dp);
    return ans;
}