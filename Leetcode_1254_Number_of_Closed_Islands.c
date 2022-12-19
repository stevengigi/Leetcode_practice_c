void dfs(int** grid, int gridSize, int* gridColSize,int row,int col){
    if(row>=gridSize || row<0 || col>=*gridColSize || col<0 || grid[row][col]!=0){
        return;
    }
    grid[row][col]=1;
    dfs(grid,gridSize,gridColSize,row-1,col);
    dfs(grid,gridSize,gridColSize,row+1,col);
    dfs(grid,gridSize,gridColSize,row,col-1);
    dfs(grid,gridSize,gridColSize,row,col+1);
}

int closedIsland(int** grid, int gridSize, int* gridColSize){
    for(int i=0;i<gridSize;i++){
        if(grid[i][0]==0){
            dfs(grid,gridSize,gridColSize,i,0);
        }
        if(grid[i][*gridColSize-1]==0){
            dfs(grid,gridSize,gridColSize,i,*gridColSize-1);
        }
    }
    printf("----------ok------------------\n");
    for(int i=0;i<*gridColSize;i++){
        if(grid[0][i]==0){
            dfs(grid,gridSize,gridColSize,0,i);
        }
        if(grid[gridSize-1][i]==0){
            dfs(grid,gridSize,gridColSize,gridSize-1,i);
        }
    }
    int res=0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<*gridColSize;j++){
            if(grid[i][j]==0){
                res++;
                dfs(grid,gridSize,gridColSize,i,j);
            }
        }
    }
    return res;
}