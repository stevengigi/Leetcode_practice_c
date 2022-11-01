char findTheDifference(char * s, char * t){
    int ans=0;
    for(int i=0;i<strlen(s);i++){
        ans^=s[i];
    }
    for(int i=0;i<strlen(t);i++){
        ans^=t[i];
    }
    return (char)ans;
}