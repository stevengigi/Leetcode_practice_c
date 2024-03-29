int bitwiseComplement(int n){
    if(n==0){
        return 1;
    }
    int count=0;
    int size=0;
    while(n!=0){
        count  = count | (!(n&0x01) << size);
        n=n>>1;
        size++;
    }
    return count;
}