int min(int a,int b){
    return  (a>b)?b:a;
}
int minFlipsMonoIncr(char * s){
    int slen=(strlen(s));
    int *one_count=(int*)calloc(slen+1,sizeof(int));
    int *zero_count=(int*)calloc(slen+1,sizeof(int));
    for(int i=1,j=slen-1;j>=0 && i<=slen;i++,j--){
        // printf("%s\n",s);
        //left to right
        one_count[i] = one_count[i-1]+(s[i-1]=='1'?1:0);
        //right to left
        zero_count[j] = zero_count[j+1]+(s[j+1]=='0'?1:0);
    }
    int ans=INT_MAX;
    for(int i=0;i<=slen;i++){
        ans=min(ans,one_count[i]+zero_count[i]);
    }
    return ans;
}