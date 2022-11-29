char * toLowerCase(char * s){
    for(int i=0;i<strlen(s);i++){

        if('Z'-s[i]<=25 && 'Z'-s[i]>=0){
            s[i]+=32;
        }
    }
    return s;
}