

int titleToNumber(char * columnTitle){
    int len=strlen(columnTitle);
    if(len==1) return *columnTitle-'A'+1;
    int ans=0;
    int index=0;
    while(len!=0){
        ans=ans*26+(columnTitle[index++]-'A'+1);
        len--;
    }
    return ans;
}