int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int heightChecker(int* heights, int heightsSize){
    int temp[heightsSize];
    for(int i=0;i<heightsSize;i++) temp[i]=heights[i];
    qsort(heights,heightsSize,sizeof(int),cmp);
    int cnt=0;
    for(int i=0;i<heightsSize;i++){
        if(temp[i]!=heights[i]) cnt++;
    }
    return cnt;
}