

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char * s, int* returnSize){
    int slen=strlen(s);
    int *res=(int*)calloc(slen,sizeof(int));
    int table[26]={0};
    *returnSize=0;
    for(int i=0;i<slen;i++){
        table[s[i]-'a']=i;
    }
    int size=0;
    int end=0;
    for(int i=0;i<slen;i++){
        size++;
        if(table[s[i]-'a'] > end ){
            end=table[s[i]-'a'];
        }
        if(i==end){
            res[(*returnSize)++]=size;
            size=0;
        }
    }
    return res;
}