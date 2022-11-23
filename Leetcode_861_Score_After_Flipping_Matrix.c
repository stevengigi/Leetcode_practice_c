int max(int a,int b){
    return a>b?a:b;
}
int matrixScore(int** grid, int gridSize, int* gridColSize){
    int rowsize=gridSize;
    int colsize=*gridColSize;

    int res=(1<<(colsize-1))*rowsize;
    for(int col=1;col<colsize;col++){
        int cnt=0;
        for(int row=0;row<rowsize;row++) cnt += (grid[row][col]==grid[row][0]);
        res += max(rowsize-cnt,cnt)*(1<<(colsize-col-1));
    }
    return res;
}