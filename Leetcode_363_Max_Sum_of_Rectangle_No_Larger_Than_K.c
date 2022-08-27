int max(int a,int b){
    return (a>b)?a:b;
}

int maxSumSubmatrix(int** matrix, int matrixSize, int* matrixColSize, int k){
    int **res=(int**)malloc(sizeof(int*)*matrixSize);
    res[0]=(int*)malloc(sizeof(int)*(*matrixColSize));
    res[0][0]=matrix[0][0];
    for(int i=1;i<matrixSize;i++){
        res[i]=(int*)malloc(sizeof(int)*(*matrixColSize));
        res[i][0]=matrix[i][0]+res[i-1][0];
    }
    for(int j=1;j<*matrixColSize;j++){
        res[0][j]=matrix[0][j]+res[0][j-1];
    }
    for(int i=1;i<matrixSize;i++){
        for(int j=1;j<*matrixColSize;j++){
            res[i][j]=matrix[i][j]+res[i-1][j]+res[i][j-1]-res[i-1][j-1];
        }
    }
    int ans=0;
    int test=INT_MIN;
    for(int row1=0;row1<matrixSize;row1++){
        for(int col1=0;col1<*matrixColSize;col1++){
            for(int row2=row1;row2<matrixSize;row2++){
                for(int col2=col1;col2<*matrixColSize;col2++){
                    if(row1==0 && col1==0){
                        ans=res[row2][col2];
                    }
                    else if(row1==0){
                        ans=res[row2][col2]-res[row2][col1-1];
                    }
                    else if(col1==0){
                        ans=res[row2][col2]-res[row1-1][col2];
                    }else{
                        ans=res[row2][col2]-res[row2][col1-1]-res[row1-1][col2]+res[row1-1][col1-1];
                    }
                    if(ans<=k){
                        test=max(test,ans);
                    }
                }
            }
        }
    }
    return test;
}