

int lengthOfLastWord(char * s){
    int len=strlen(s);
    while(s[len-1]==' '){
        len--;
    }
    int index=0;
    while(s[len-1]!=' '){
        index++;
        len--;
        if(len <= 0){
            break;
        }

    }
    return index;
}