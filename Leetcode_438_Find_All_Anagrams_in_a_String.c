bool issame(int *x, int *y)
{
    for(int i = 0; i < 26; i++)
        if(x[i] != y[i])
            return false;
    return true;
}

int* findAnagrams(char * s, char * p, int* returnSize){
    int slen=strlen(s);
    int plen=strlen(p);
    *returnSize=0;
    if(slen < plen){
        return NULL;
    }
    int pcount[26]={0};
    int scount[26]={0};
    int *ans=(int*)calloc(slen,sizeof(int));
    for(int i=0;i<plen;i++){
        pcount[p[i]-'a']++;
    }
    for(int i=0;i<slen;i++){
        scount[s[i]-'a']++;
        if(i>=plen){
            scount[s[i-plen]-'a']--;
        }
        if(issame(pcount,scount)){
            ans[*returnSize]=i-plen+1;
            (*returnSize)++;
        }
    }
    return ans;
}