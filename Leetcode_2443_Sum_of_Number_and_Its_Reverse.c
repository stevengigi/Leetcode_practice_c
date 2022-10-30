int rev(int x){
    int ans=0;
    while(x!=0){
        ans=ans*10+x%10;
        x/=10;
    }
    return ans;
}

bool sumOfNumberAndReverse(int num){
    if(num==0) return true;
    for(int i=num/2;i<num;i++){
        if(i+rev(i)==num){
            return true;
        }
    }
    return false;
}