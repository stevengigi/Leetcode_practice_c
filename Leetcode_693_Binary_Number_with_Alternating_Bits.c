bool hasAlternatingBits(int n){
    int cur=n%2;
    n/=2;
    while(n>0){
        if(cur==n%2) return 0;
        cur=n%2;
        n/=2;
    }
    return 1;
}
