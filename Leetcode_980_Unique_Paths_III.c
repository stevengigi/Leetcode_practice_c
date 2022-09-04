int uniquePathsIII(int** a, int n, int* colSize){
    int *ans = (int*)malloc(sizeof(int));
    *ans = 0;
    int x, y;
    int availStep = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<colSize[i]; j++) {
            if (a[i][j] == 1) {
                x = i;
                y = j;
            }
            if (a[i][j] != -1)
                availStep++;
        }

    DFS(a, n, colSize, x+1, y, ans, 1, availStep);
    DFS(a, n, colSize, x-1, y, ans, 1, availStep);
    DFS(a, n, colSize, x, y+1, ans, 1, availStep);
    DFS(a, n, colSize, x, y-1, ans, 1, availStep);
    return *ans;
}

void DFS(int** a, int n, int* colSize, int x, int y, int* ans, int step, int availStep) {
    if (x<0 || x>=n || y<0 || y>=colSize[x] || a[x][y] == -1 || a[x][y] == 1)
        return;

    if (a[x][y] == 2) {
        if (step+1 == availStep)
            (*ans)++;;
        return;
    }

    a[x][y] = -1;
    DFS(a, n, colSize, x+1, y, ans, step+1, availStep);
    DFS(a, n, colSize, x-1, y, ans, step+1, availStep);
    DFS(a, n, colSize, x, y+1, ans, step+1, availStep);
    DFS(a, n, colSize, x, y-1, ans, step+1, availStep);
    a[x][y] = 0;
    return;
}