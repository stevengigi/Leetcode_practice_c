

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backtrack(char **res,char *s,int slen,int pos,int* returnSize){
    if(pos==slen){
        char *temp=(char*)calloc((slen+1),sizeof(char));
        memcpy(temp,s,slen);
        printf("temp : %s | returnsize : %d\n",temp,*returnSize);
        res[(*returnSize)++]=temp;
        return;
    }
    backtrack(res,s,slen,pos+1,returnSize);
    if(((s[pos]-'a')>=0 && (s[pos]-'a')<26) || ((s[pos]-'A')<26 && (s[pos]-'A')>=0)){
        s[pos]^=(1<<5);
        backtrack(res,s,slen,pos+1,returnSize);
    }
}
char ** letterCasePermutation(char * s, int* returnSize){
    *returnSize=0;
    char **res=(char**)malloc(sizeof(char*)*4096);

    backtrack(res,s,strlen(s),0,returnSize);

    res=realloc(res,*returnSize*sizeof(char*));
    printf("coming in \n");
    return res;
}