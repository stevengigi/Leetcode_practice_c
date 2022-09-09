
int cmp( const void *pa, const void *pb ) {
    const int *a = *(const int **)pa;
    const int *b = *(const int **)pb;
    if(a[0] == b[0])
        return b[1] - a[1]; // 大到小 ex [ [2,3] [2,5] ]=> [ [2,5] [2,3] ]
    else
        return a[0] - b[0]; // ex: [ [3 3] [2 4] ] => [ [2 4] [3 3] ]
}

int max(int a,int b){
    return (a>b)?a:b;
}
int numberOfWeakCharacters(int** properties, int propertiesSize, int* propertiesColSize){
    qsort(properties,propertiesSize,sizeof(properties[0]),cmp);
    int dfs=INT_MIN;
    int ans=0;
    for(int i=propertiesSize-1;i>=0;i--){
        printf("for : %d  %d\n",properties[i][0],properties[i][1]);
        if(properties[i][1] < dfs){
            printf("in : %d  %d\n",properties[i][0],properties[i][1]);
            ans++;
        }
        dfs=max(dfs,properties[i][1]);
    }
    return ans;
}