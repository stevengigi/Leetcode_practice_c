

char * reformatNumber(char * number){
    int len=0;
    char temp[strlen(number)];
    while(*number!='\0'){
        if(*number-'0' >=0 && *number-'0' <=9){
            temp[len]=*number;
            len++;
        }
        *(number++);
    }
    printf("%d",len);
    char *res=(char*)malloc(sizeof(char)*(len+1+len/3+2));
    int index=0;
    int temp_index=0;
    while(len>0){
        if(len==4){
            for(int i=0;i<2;i++){
                res[index++]=temp[temp_index++];
            }
            res[index++]='-';
            len-=2;
        }
        else if(len>3 && len!=4){
            for(int i=0;i<3;i++){
                res[index++]=temp[temp_index++];
            }
            res[index++]='-';
            len-=3;
        }
        else if(len<=3){
            for(int i=0;i<len;i++){
                res[index++]=temp[temp_index++];
            }
            len=0;
            break;
        }
    }
    res[index]='\0';
    return res;
}