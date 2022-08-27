


typedef struct {
    int colsize;
    int rowsize;
    int **sum;
} NumMatrix;


NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    NumMatrix *obj=(NumMatrix*)malloc(sizeof(NumMatrix));
    obj->rowsize=matrixSize;
    obj->colsize=*matrixColSize;
    obj->sum=(int**)malloc(sizeof(int*)*obj->rowsize);
    for(int i=0;i<obj->rowsize;i++){
        obj->sum[i]=(int*)malloc(sizeof(int)*obj->colsize);
    }
    obj->sum[0][0]=matrix[0][0];
    for(int i=1;i<obj->rowsize;i++){
        obj->sum[i][0]=obj->sum[i-1][0]+matrix[i][0];
    }
    for(int i=1;i<obj->colsize;i++){
        obj->sum[0][i]=obj->sum[0][i-1]+matrix[0][i];
    }
    for(int i=1;i<obj->rowsize;i++){
        for(int j=1;j<obj->colsize;j++){
            obj->sum[i][j]=obj->sum[i][j-1]+obj->sum[i-1][j]+matrix[i][j]-obj->sum[i-1][j-1];
        }
    }

    return obj;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    if(row1==0 && col1==0){
      return obj->sum[row2][col2];
    }
    if(row1==0){
        return obj->sum[row2][col2]-obj->sum[row2][col1-1];
    }
    if(col1==0){
        return obj->sum[row2][col2]-obj->sum[row1-1][col2];
    }
    return obj->sum[row2][col2]-obj->sum[row2][col1-1]-obj->sum[row1-1][col2]+obj->sum[row1-1][col1-1];
}

void numMatrixFree(NumMatrix* obj) {
    for(int i=0;i<obj->rowsize;i++){
        free(obj->sum[i]);
    }
    free(obj->sum);
    free(obj);
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);

 * numMatrixFree(obj);
*/