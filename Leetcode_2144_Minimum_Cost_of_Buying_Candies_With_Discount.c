int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}

int minimumCost(int* cost, int costSize){
    qsort(cost,costSize,sizeof(int),cmp);
    int c=0;
    for(int i=0;i<costSize;i++){
        if(i%3!=costSize%3){
           c+=cost[i];
        }
    }
    return c;
}