

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int *res=(int*)malloc(sizeof(int)*matrixSize*matrixColSize[0]);
    *returnSize=matrixSize*matrixColSize[0];
    int left=0,right=matrixColSize[0]-1;
    int up=0,down=matrixSize-1;
    int index=0;
    while(left <=right || up <=down){
        if(up<=down){
            for(int i=left;i<=right;i++){
                res[index++]=matrix[up][i];
            }
            up++;
        }
        if(left<=right){
            for(int i=up;i<=down;i++){
                res[index++]=matrix[i][right];
            }
            right--;
        }
        if(up<=down){
            for(int i=right;i>=left;i--){
                res[index++]=matrix[down][i];
            }
            down--;
        }
        if(left<=right){
            for(int i=down;i>=up;i--){
                res[index++]=matrix[i][left];
            }
            left++;
        }
    }
    return res;
}