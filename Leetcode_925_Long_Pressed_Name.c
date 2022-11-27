bool isLongPressedName(char * name, char * typed){
    int nlen=strlen(name);
    int tlen=strlen(typed);
    int n=0,t=0;
    while(n<nlen && t<tlen){
        if(name[n]==typed[t]){
            n++;
            t++;
        }else if(t>=1 && typed[t]==typed[t-1]){
            t++;
        }else return false;
    }
    printf("n: %d | t:%d",n,t);
    while(t<tlen){
        if(typed[t]==typed[t-1]) t++;
        else break;
    }
    if(n==nlen && t==tlen) return true;
    else return false;
}