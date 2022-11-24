int max(int a,int b){
    return a>b?a:b;
}
int largestCombination(int* candidates, int candidatesSize){
    int res=0;
    for(int i=0;i<31;i++){
        int cur=0;
        for(int j=0;j<candidatesSize;j++){
            cur += 1&(candidates[j]>>i);
        }
        res=max(res,cur);
    }
    return res;
}