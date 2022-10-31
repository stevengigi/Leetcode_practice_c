bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize){
    for(int row=0;row<matrixSize;row++){
        for(int col=0;col<*matrixColSize;col++){
            if(row>0 && col>0 && matrix[row-1][col-1]!=matrix[row][col]){
                return false;
            }
        }
    }
    return true;
}