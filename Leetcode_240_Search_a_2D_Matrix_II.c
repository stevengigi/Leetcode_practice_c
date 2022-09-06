
#define error -10000000001
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row=0;
    int col=matrixColSize[0]-1;

    while(true){
        printf("row : %d col : %d\n",row,col);
        // printf(" %d \n",matrix[row][col]);
        if(row<0 || row >=matrixSize || col<0 || col >=matrixColSize[0] || matrix[row][col]==error){
            return false;
        }
        if(matrix[row][col]==target){
            return true;
        }
        if(matrix[row][col]>target){
            matrix[row][col]=error;
            col--;
            continue;
        }
        if(matrix[row][col]<target){
            matrix[row][col]=error;
            row++;
            continue;
        }
    }
}