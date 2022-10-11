int min(int a,int b){
    return (a>b)?b:a;
}
int max(int a,int b){
    return (a>b)?a:b;
}
int gcd(int a,int b){
    int small=min(a,b);
    int large=max(a,b);
    int r=small;
    while(small!=0){
        int r=large % small;
        large=small;
        small=r;
    }
    return large;
}

int commonFactors(int a, int b){
    int res=1;
    for(int i=2;i<=gcd(a,b);i++){
        res+= a%i==0 && b%i==0;
    }
    return res;
}

