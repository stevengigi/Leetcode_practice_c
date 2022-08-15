
char map[10][5]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void search(int index,char **res,int len,char *restemp,int *returnSize,char *digits){
    if(index==len){
        restemp[index]='\0';
        char *temp=(char*)malloc((len+1)*sizeof(char));
        strncpy(temp,restemp,(len+1));
        res[(*returnSize)++]=temp;
    }else{
        char *substring=map[digits[index]-'0'];
        for(int i=0;i<strlen(substring);i++){
            restemp[index]=substring[i];
            search(index+1,res,len,restemp,returnSize,digits);
        }
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    int len=strlen(digits); // 每一個子字串的長度
    int size=1;
    *returnSize=0;
    if(len==0){
        return NULL;
    }
    for(int i=0;i<len;i++){
        size*=strlen(map[digits[i]-'0']);
    }

    char **res=(char**)malloc(size*sizeof(char*));
    char *restemp=(char*)malloc((len+1)*sizeof(char));
    search(0,res,len,restemp,returnSize,digits);
    free(restemp);
    return res;
}

