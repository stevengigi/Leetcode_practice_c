

char * removeDigit(char * number, char digit){
    int len=strlen(number);
    char *s=(char*)malloc(sizeof(char)*len);
    memset(s,0,len);
    int right;
    for(int i=0;i<len;i++){
        if(number[i]==digit){
            right=i;
            if(i+1 != len && number[i]<number[i+1]){
                break;
            }
        }
    }
    printf("ok\n");
    printf("%d\n",right);
    int index=0;
    for(int i=0;i<right;i++){
        s[index++]=number[i];
    }
    for(int i=right+1;i<len;i++){
        s[index++]=number[i];
    }

    return s;
}