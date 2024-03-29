struct pair{
    int planttime;
    int growtime;
};

int cmp(const void *a,const void *b){
    struct pair aa=*(struct pair*)a;
    struct pair bb=*(struct pair*)b;
    return aa.growtime-bb.growtime;
}

int max(int a,int b){
    return a>b?a:b;
}

int earliestFullBloom(int* plantTime, int plantTimeSize, int* growTime, int growTimeSize){
    struct pair p[plantTimeSize];
    for(int i=0;i<plantTimeSize;i++){
        p[i].planttime=plantTime[i];
        p[i].growtime=growTime[i];
    }
    qsort(p,growTimeSize,sizeof(struct pair),cmp);
    // for(int i=0;i<plantTimeSize;i++){
    //     printf("planttime : %d | growtime :%d\n",p[i].planttime,p[i].growtime);
    // }
    int ans=0;;
    for(int i=0;i<growTimeSize;i++){
        ans=max(ans,p[i].growtime)+p[i].planttime;
    }
    return ans;
}