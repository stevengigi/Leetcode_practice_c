char * removeDuplicates(char * s){
    int i=0;
    for(int j=0;j<strlen(s);j++,i++){
        s[i]=s[j];
        if(i>0 && s[i-1]==s[i]){
            i-=2;
        }
    }
    s[i]='\0';
    printf("s : %s | i : %d",s,i);
    return s;
}