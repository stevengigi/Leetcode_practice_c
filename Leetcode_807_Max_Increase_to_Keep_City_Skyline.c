int min(int a,int b){
    return (a>b)?b:a;
}

int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
    int *row=(int*)calloc(gridSize,sizeof(int));
    int *col=(int*)calloc(gridSize,sizeof(int));

    for(int i=0;i<gridSize;i++){
        int maxcol=-1;
        int maxrow=-1;
        for(int j=0;j<gridColSize[0];j++){
            if(grid[i][j] > maxrow){
                maxrow=grid[i][j];
            }
            if(grid[i][j]>col[j]){
                col[j]=grid[i][j];
            }
        }
        row[i]=maxrow;
    }
    int ans=0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[0];j++){
            if(grid[i][j]==col[j] || grid[i][j]==row[i]){
                continue;
            }else if(col[j] > row[i]){
                ans+=row[i]-grid[i][j];
            }else{
                ans+=col[j]-grid[i][j];
            }
        }
    }
    // for(int i=0;i<gridSize;i++){
    //     printf(" %d ",row[i]);
    // }
    // printf("\n");
    // for(int i=0;i<gridSize;i++){
    //     printf(" %d ",col[i]);
    // }
    return ans;
}