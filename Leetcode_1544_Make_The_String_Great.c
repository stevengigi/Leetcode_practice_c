char * makeGood(char * s){
    int slen=strlen(s);
    int top=0;
    char *res=(char*)malloc(sizeof(char)*(slen+1));

    for(int i=0;i<slen;i++){
        res[top]=s[i];
        if (top > 0 && (res[top] + 32 == res[top-1] || res[top] - 32 == res[top-1])) top -= 2;
        top++;
    }
    res[top]='\0';
    return res;
}