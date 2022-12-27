int min(int a,int b){
    return a>b?b:a;
}

int countSquares(int** matrix, int matrixSize, int* matrixColSize){
    int res=0;
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<*matrixColSize;j++){
            // printf("i : %d | j :%d ok\n",i,j);
            if(matrix[i][j]>0 && i>0 && j>0){
                matrix[i][j]=min(matrix[i-1][j],min(matrix[i-1][j-1],matrix[i][j-1]))+1;
            }
            res+=matrix[i][j];
        }
    }
    return res;
}