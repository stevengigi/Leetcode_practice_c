void dfs(char **grid ,int row ,int rowsize,int col ,int colsize){
    grid[row][col]='0';
    if(row+1 < rowsize && grid[row+1][col]=='1'){
        dfs(grid,row+1,rowsize,col,colsize);
    }
    if(row-1>=0 && grid[row-1][col]=='1'){
        dfs(grid,row-1,rowsize,col,colsize);
    }
    if(col-1 >=0 && grid[row][col-1]=='1'){
        dfs(grid,row,rowsize,col-1,colsize);
    }
    if(col+1 < colsize && grid[row][col+1]=='1'){
        dfs(grid,row,rowsize,col+1,colsize);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int rowsize=gridSize;
    int colsize=*gridColSize;
    int res=0;
    for(int r=0;r<rowsize;r++){
        for(int c=0;c<colsize;c++){
            if(grid[r][c]=='1'){
                dfs(grid,r,rowsize,c,colsize);
                res++;
            }
        }
    }
    return res;
}