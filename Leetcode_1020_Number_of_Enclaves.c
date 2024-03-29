void dfs(int** grid, int r, int c, int rSize, int cSize) {
    if(r < 0 || c < 0 || r > rSize-1 || c > cSize-1 || grid[r][c] == 0 || grid[r][c] == -1) return;
    grid[r][c] = -1;
    dfs(grid, r+1, c, rSize, cSize);
    dfs(grid, r-1, c, rSize, cSize);
    dfs(grid, r, c+1, rSize, cSize);
    dfs(grid, r, c-1, rSize, cSize);
}

int numEnclaves(int** grid, int gridSize, int* gridColSize) {
    int rSize = gridSize, cSize = gridColSize[0], ans = 0;
    for(int c = 0; c < cSize; c++) {
        if(grid[0][c] == 1) dfs(grid, 0, c, rSize, cSize);
        if(grid[rSize-1][c] == 1) dfs(grid, rSize-1, c, rSize, cSize);
    }
    for(int r = 1; r < rSize-1; r++) {
        if(grid[r][0] == 1) dfs(grid, r, 0, rSize, cSize);
        if(grid[r][cSize-1] == 1) dfs(grid, r, cSize-1, rSize, cSize);
    }
    for(int r = 0; r < rSize; r++) {
        for(int c = 0; c < cSize; c++) {
            if(grid[r][c] == 1) ans++;
        }
    }
    return ans;
}