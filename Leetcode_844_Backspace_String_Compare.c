

bool backspaceCompare(char * s, char * t){
    int slen=strlen(s);
    int tlen=strlen(t);
    int index1=-1;
    int index2=-1;
    for(int i=0;i<slen;i++){
        if(s[i]!='#'){
            s[++index1]=s[i];
        }else if(s[i]=='#'){
            if(index1==-1){
                continue;
            }else{
                --index1;
            }
        }
    }
    s[++index1]='\0';
    printf("s : %s\n",s);
    for(int i=0;i<tlen;i++){
        if(t[i]!='#'){
            t[++index2]=t[i];
        }else if(t[i]=='#'){
            if(index2==-1){
                continue;
            }else{
                --index2;
            }
        }
    }
    t[++index2]='\0';
    printf("t: %s\n",t);
    return !strcmp(t,s);

}