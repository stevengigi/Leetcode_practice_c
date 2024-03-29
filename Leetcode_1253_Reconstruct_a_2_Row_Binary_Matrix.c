

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reconstructMatrix(int upper, int lower, int* colsum, int colsumSize, int* returnSize, int** returnColumnSizes){
    *returnSize=0;
    *returnColumnSizes=(int*)calloc(2,sizeof(int));
    int **res=(int**)malloc(sizeof(int*)*2);
    for(int i=0;i<2;i++){
        res[i]=(int*)calloc(colsumSize,sizeof(int));
    }
    for(int i=0;i<colsumSize;i++){
        if(lower < 0 || upper < 0 ){
            return res;
        }
        if(colsum[i]==1){
            if(upper > lower){
                res[0][i]=1;
                upper--;
            }else{
                res[1][i]=1;
                lower--;
            }
        }else if(colsum[i]==2){
            res[0][i]=1;
            res[1][i]=1;
            upper--;
            lower--;
        }
    }
    if(upper==0 && lower==0){
        *returnSize=2;
        (*returnColumnSizes)[0] = colsumSize;
        (*returnColumnSizes)[1] = colsumSize;

    }
    return res;
}