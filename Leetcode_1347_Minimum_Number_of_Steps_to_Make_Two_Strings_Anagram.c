int minSteps(char * s, char * t){
    int stack[26]={0};
    for(int i=0;i<strlen(s);i++){
        stack[s[i]-'a']++;
        stack[t[i]-'a']--;
    }
    int res=0;
    for(int i=0;i<26;i++){
        if(stack[i]<0){
            res+=-stack[i];
        }
    }
    return res;
}