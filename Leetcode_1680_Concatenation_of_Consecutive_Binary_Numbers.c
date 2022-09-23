#define e 1000000007

int concatenatedBinary(int n){
    // if(n==1){
    //     return 1;
    // }
    long long  ans=0;
    int count=0;
    for(int i=1;i<=n;i++){
        if((i & (i-1))==0){
            count++;
        }
        ans=((ans << count)%e+i)%e;
    }
    return ans;
}