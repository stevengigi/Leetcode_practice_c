int max(int a,int b){
    return (a>b)?a:b;
}

char * pushDominoes(char * dominoes){
    int len=strlen(dominoes);
    char *res=(char*)malloc(sizeof(char)*(len+1));
    int *temp=(int*)calloc(len,sizeof(int));

    int force=0;
    // right to left
    for(int i=0;i<len;i++){
        if(dominoes[i]=='R') force=len;
        else if(dominoes[i]=='L') force=0;
        else force=max(force-1,0);
        temp[i]=force;
    }
    force=0;
    //right to left
    for(int i=len-1;i>=0;i--){
        if(dominoes[i]=='L') force=len;
        else if(dominoes[i]=='R') force=0;
        else force=max(force-1,0);
        temp[i]-=force;
    }
    for(int i=0;i<len;i++){
        res[i]=(temp[i]>0)?'R':((temp[i]<0)?'L':'.');
    }
    res[len]='\0';
    return res;
}