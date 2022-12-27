int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int maximumBags(int* capacity, int capacitySize, int* rocks, int rocksSize, int additionalRocks){
    int count[capacitySize];
    for(int i=0;i<capacitySize;i++){
        count[i]=capacity[i]-rocks[i];
        printf(" %d ",count[i]);
    }
    qsort(count,rocksSize,sizeof(int),cmp);
    int i;

    for(i=0;i<capacitySize && additionalRocks>=count[i];i++){
        additionalRocks-=count[i];
    }
    return i;
}