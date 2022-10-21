int cmp(const void *a,const void *b){
    int *test1=*(int**)a;
    int *test2=*(int**)b;
    if(test1[1]==test2[1]){
        return  test1[0]-test2[0];
    }
    return  test1[1]-test2[1];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    qsort(intervals,intervalsSize,sizeof(int*),cmp);
    int cnt=0;
    int end=intervals[0][1];
    printf("intervalsSize start : %d | end : %d\n",intervals[0][0],intervals[0][1]);
    for(int i=1;i<intervalsSize;i++){
        printf("intervalsSize start : %d | end : %d\n",intervals[i][0],intervals[i][1]);
        if(intervals[i][0]<end){ //start < end
            cnt++;
        }else{
            end=intervals[i][1];
        }
    }
    return cnt;
}
