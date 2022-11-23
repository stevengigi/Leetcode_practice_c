int max(int a,int b){
    return a>b?a:b;
}
int maxRepeating(char * sequence, char * word){
    int wlen=strlen(word);
    int slen=strlen(sequence);
    int ans;
    int res=0;
    for(int i=0;i<slen-wlen+1;i++){
        if(strncmp(&sequence[i],word,wlen)!=0){
            continue;
        }
        else{
            ans=1;
            for(int j=i+wlen;j<slen-wlen+1;j+=wlen){
                if(strncmp(&sequence[j],word,wlen)==0) ans++;
                else break;
            }
            res=max(res,ans);
        }

    }
    return res;
}