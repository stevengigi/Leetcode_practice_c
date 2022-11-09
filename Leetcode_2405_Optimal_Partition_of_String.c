int partitionString(char * s){
    int pos[26]={0};
    int last=0;
    int res=0;
    for(int i=0;i<strlen(s);i++){
        if(pos[s[i]-'a'] >= last){
            ++res;
            last=i+1;
        }
        pos[s[i]-'a']=i+1;
    }
    return res;
}