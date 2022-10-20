

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    // 1   2  3  4
    //12  13 14  5
    //11  16 15  6
    //10   9  8  7
    *returnSize=n;
    int **matrix =(int**)malloc(sizeof(int*)*(n));
    *returnColumnSizes=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        matrix[i]=(int*)calloc(n,sizeof(int));
        (*returnColumnSizes)[i]=n;
    }
    if(n==0){
        return matrix;
    }
    printf("-----------------\n");
    int rowstart=0;
    int rowend=n-1;
    int colend=n-1;
    int colstart=0;
    int cnt=1;
    while(rowstart<=rowend && colstart <=colend){
        for(int i=colstart;i<=colend;i++){
            matrix[rowstart][i]=cnt;
            cnt++;
        }
        printf("rowstart :%d | rowend : %d | colstart : %d | colend :%d\n",rowstart,rowend,colstart,colend);
        rowstart++;

        for(int i=rowstart;i<=rowend;i++){
            matrix[i][colend]=cnt;
            cnt++;
        }
        printf("rowstart :%d | rowend : %d | colstart : %d | colend :%d\n",rowstart,rowend,colstart,colend);
        colend--;
        for(int i=colend;i>=colstart;i--){
            matrix[rowend][i]=cnt++;
        }
        printf("rowstart :%d | rowend : %d | colstart : %d | colend :%d\n",rowstart,rowend,colstart,colend);
        rowend--;
        for(int i=rowend;i>=rowstart;i--){
            matrix[i][colstart]=cnt++;
        }
        printf("rowstart :%d | rowend : %d | colstart : %d | colend :%d\n",rowstart,rowend,colstart,colend);
        colstart++;
    }
    return matrix;
}


