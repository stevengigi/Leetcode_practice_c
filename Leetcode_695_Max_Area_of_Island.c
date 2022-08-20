int max(int a,int b){
    return (a>b)?a:b;
}
int dfs(int **grid,int row,int rowsize,int col,int colsize){
    if(row<0 || row>=rowsize || col <0 || col>=colsize || grid[row][col]==0){
        return 0;
    }
    grid[row][col]=0;
    return (1+dfs(grid,row-1,rowsize,col,colsize)+dfs(grid,row+1,rowsize,col,colsize)+dfs(grid,row,rowsize,col-1,colsize)+dfs(grid,row,rowsize,col+1,colsize));
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int rowsize=gridSize;
    int colsize=*gridColSize;
    int ans=0;
    for(int r=0;r<rowsize;r++){
        for(int c=0;c<colsize;c++){
            ans=max(ans,dfs(grid,r,rowsize,c,colsize));
        }
    }
    return ans;
}