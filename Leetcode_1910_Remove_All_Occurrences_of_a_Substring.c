char * removeOccurrences(char * s, char * part){
    int slen=strlen(s);
    int plen=strlen(part);
    char *res=(char*)calloc((slen+1),sizeof(char));
    int start=0;
    for(int i=0;i<slen;i++){
        res[start++]=s[i];
        printf("--res : %s--| s : %s- \n",res,&s[i]);
        if(start>=plen && (!strncmp(&res[start-plen],part,plen))){

            start-=plen;
            printf("------go in --| start : %d\n",start);
            for(int i=start;i<start+plen;i++){
                res[i]='\0';
            }
        }
    }

    res[start]='\0';
    return res;
}