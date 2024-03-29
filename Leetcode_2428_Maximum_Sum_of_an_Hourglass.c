int max(int a,int b){
    return (a>b)?a:b;
}

int maxSum(int** grid, int gridSize, int* gridColSize){
    if(gridSize==3 && *gridColSize==3){
        return grid[0][0]+grid[0][1]+grid[0][2]+grid[1][1]+grid[2][0]+grid[2][1]+grid[2][2];
    }
    int res=INT_MIN;
    for(int i=0;i<gridSize-2;i++){
        for(int j=0;j<*gridColSize-2;j++){
            res=max(res,grid[i][j]+grid[i][j+1]+grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]);
        }
    }
    return res;
}