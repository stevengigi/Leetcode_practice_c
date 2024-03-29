int max(int a,int b){
    return (a>b)?a:b;
}

int maxProduct(char ** words, int wordsSize){
    int *len=(int*)malloc(sizeof(int)*wordsSize);
    int *mask=(int*)calloc(wordsSize,sizeof(int));
    for(int i=0;i<wordsSize;i++){
        len[i]=strlen(words[i]);
    }
    int res=0;
    for(int i=0;i<wordsSize;i++){
        for(int j=0;j<len[i];j++){
            mask[i] |=  (1 << (words[i][j]-'a'));
        }
        for(int j=0;j<i;j++){
            if(!(mask[i]&mask[j])){
              res=max(res,len[i]*len[j]);
            }
        }
    }
    free(mask);
    free(len);
    return res;
}