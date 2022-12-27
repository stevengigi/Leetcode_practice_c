bool checkZeroOnes(char * s){
    int slen=strlen(s);
    if(slen==1) return s[0]=='1'?true:false;
    int last_index=s[0]-'0';
    int max_size_zero=0;
    int max_size_one=0;
    int size=1;
    for(int i=1;i<slen;i++){
        int temp=s[i]-'0';
        if(last_index!=temp){
            if(last_index==0){
                max_size_zero=max_size_zero<size?size:max_size_zero;
            }else{
                max_size_one=max_size_one<size?size:max_size_one;
            }
            size=1;
            last_index=temp;
        }else{
            size++;
        }
    }
    if(last_index==0){
        max_size_zero=max_size_zero<size?size:max_size_zero;
    }else{
        max_size_one=max_size_one<size?size:max_size_one;
    }
    return max_size_one>max_size_zero;
}