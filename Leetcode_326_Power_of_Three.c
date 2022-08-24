bool isPowerOfThree(int n){
    if(n<=0){
        return false;
    }
    while(n!=1){
        if(n%3==0)
        {
            printf("%d ",n);
            n=n/3;
        }else{
            return false;
        }
    }
    return true;
}