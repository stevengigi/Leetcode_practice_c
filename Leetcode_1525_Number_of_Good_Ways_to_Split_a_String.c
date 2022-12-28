int numSplits(char * s){
    int table[26]={0};
    int left_table[26]={0};
    int s_left=0,s_right=0;
    int res=0;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        table[s[i]-'a']++;
        s_right+=(table[s[i]-'a']==1);
    }
    for(int i=0;i<len;i++){
        s_left+=(++left_table[s[i]-'a'])==1;
        s_right-=(--table[s[i]-'a'])==0;
        res+=s_left==s_right;
    }
    return res;
}