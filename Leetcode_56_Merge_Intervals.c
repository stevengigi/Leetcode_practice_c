int cmp(const void *a, const void *b){
    int **a1=(int**)a;
    int **b1=(int**)b;
    if(a1[0][0]!=b1[0][0]){
        return a1[0][0]-b1[0][0];
    }else{
        return a1[0][1]-b1[0][1];
    }
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    if(intervalsSize==1){
        return intervals;
    }
    qsort(intervals,intervalsSize,sizeof(intervals[0]),cmp);
    int **res=(int**)malloc(sizeof(int*)*intervalsSize);
    res[0]=(int *)malloc(sizeof(int)*2);

    res[0][0]=intervals[0][0];
    res[0][1]=intervals[0][1];

    int count=1;
    for(int i=1;i<intervalsSize;i++){
        if(res[count-1][1]<intervals[i][0]){
            res[count]=(int*)malloc(sizeof(int)*2);
            res[count][0]=intervals[i][0];
            res[count][1]=intervals[i][1];
            count++;
        }
        else if(res[count-1][1] >= intervals[i][0]){
            if (res[count-1][1] < intervals[i][1]) {
                res[count-1][1] = intervals[i][1];
            }
        }
    }
    *returnSize = count;
    *returnColumnSizes=(int *)malloc(count*sizeof(int));
    for(int i=0;i<count;i++){
        (*returnColumnSizes)[i]=2;
    }
    return res;
}