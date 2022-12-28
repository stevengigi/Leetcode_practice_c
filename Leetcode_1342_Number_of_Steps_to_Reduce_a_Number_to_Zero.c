int numberOfSteps(int num){
    int res=0;
    while(num){
        if(num==1){
            res++;
            break;
        }
        int temp=(num&0x01);
        num>>=1;
        res+=temp==1?2:1;
    }
    return res;
}