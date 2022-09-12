

int strStr(char * haystack, char * needle){
    int len=strlen(haystack);
    if(len==0){
        return -1;
    }
    int len2=strlen(needle);
    for(int i=0;i<=len-len2;i++){
        if(!strncmp((haystack+i),needle,len2)) return i;
    }
    return -1;
}