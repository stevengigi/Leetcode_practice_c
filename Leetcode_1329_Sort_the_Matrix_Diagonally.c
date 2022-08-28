int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int** diagonalSort(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
    int rsize=matSize;
    int csize=*matColSize;
    int **res=(int**)malloc(sizeof(int*)*rsize);
    int *temp=(int*)malloc(sizeof(int)*csize);
    *returnSize=rsize;
    *returnColumnSizes = (int*) malloc(rsize * sizeof(int));
    for(int i=0;i<rsize;i++){
        (*returnColumnSizes)[i]=csize;
        res[i]=(int*)malloc(sizeof(int)*csize);
    }
    // printf("ok");
    res[rsize-1][0]=mat[rsize-1][0];
    res[0][csize-1]=mat[0][csize-1];
    for(int r=rsize-2;r>=0;r--){
        int index=0;
        int rindex=r;
        int cindex=0;
        while(cindex < csize && rindex < rsize){
            temp[index++]=mat[rindex++][cindex++];
        }
        qsort(temp,index,sizeof(int),cmp);

        for(int i=index-1;i>=0;i--){
            // printf(" %d ",temp[i]);
            // printf("ok");
            res[--rindex][--cindex]=temp[i];
        }
    }
    // printf("ok");
    for(int c=1;c<=csize-2;c++){
        int index=0;
        int cindex=c;
        int rindex=0;
        while( cindex < csize && rindex < rsize){
            temp[index++]=mat[rindex++][cindex++];
        }
        qsort(temp,index,sizeof(int),cmp);
        for(int i=index-1;i>=0;i--){
            // printf(" %d ",temp[i]);
            res[--rindex][--cindex]=temp[i];
        }
    }
    // printf("ok\n");
    free(temp);
    // for(int r=0;r<rsize;r++){
    //     for(int c=0;c<csize;c++){
    //         printf(" %d ",res[r][c]);
    //     }
    //     printf("\n");
    // }
    return res;
}