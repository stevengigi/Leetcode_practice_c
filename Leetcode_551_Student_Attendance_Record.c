bool checkRecord(char * s){
    int late=0;
    int absent=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='A'){
            absent++;
            if(absent>=2) return false;
        }
        else if(s[i]=='L'){
            if(i!=0 && s[i-1]=='L'){
                late++;
                if(late >=3) return false;
            }
            else late=1;
        }
    }
    return true;
}