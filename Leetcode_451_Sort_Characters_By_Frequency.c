struct map{
    int count;
    char c;
};
// 122-48=74

int cmp(const void *a,const void *b){
    int aa=((struct map *)a)->count;
    int bb=((struct map *)b)->count;
    return bb-aa;
}
char * frequencySort(char * s){
    struct map table[75]={0,0};
    int slen=strlen(s);
    for(int i=0;i<slen;i++){
        if(table[s[i]-'0'].count==0){
            table[s[i]-'0'].c=s[i];
        }
        table[s[i]-'0'].count++;
    }
    qsort(table,75,sizeof(struct map),cmp);
    int index=0;
    for(int i=0;i<75;i++){
        for(int j=0;j<table[i].count;j++){
            s[index++]=table[i].c;
        }
    }
    return s;
}