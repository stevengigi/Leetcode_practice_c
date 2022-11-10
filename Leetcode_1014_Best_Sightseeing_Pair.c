int max(int a,int b){
    return a>b?a:b;
}
int maxScoreSightseeingPair(int* values, int valuesSize){
    int res=0,cur=0;
    for(int i=0;i<valuesSize;i++){
        res=max(res,cur+values[i]);
        cur=max(cur,values[i])-1;
    }
    return res;
}