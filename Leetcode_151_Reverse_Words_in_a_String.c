char *process(char *s,int slen,char *res,int start,int end){
    int index=0;
    int end_index=end;
    int copy_len;
    for(int i=end;i>=start;i--){
        if(s[i]==' '){
            printf("start----- i : %d\n",i);
            copy_len=end_index-i;

            for(int k=0;k<copy_len;k++){
                res[index+k]=s[i+1+k];
            }

            index+=copy_len;
            res[index++]=' ';
            while(s[i]==' '){
                i--;
            }
            end_index=i;
            i++;
            printf("end ------ i : %d\n",i);
        }
        else if(i==start){
            copy_len=end_index-i+1;
            strncpy(&res[index],&s[i],copy_len);
            index+=copy_len;
            res[index]='\0';
        }
    }
    return res;
}

char * reverseWords(char * s){
    int len=strlen(s);
    char *res=(char*)malloc(sizeof(char)*(len+1));
    int end=len-1;
    int start=0;
    while(s[start]==' '){
        start++;
    }
    while(s[end]==' '){
        end--;
    }
    for(int i=start;i<=end;i++){
        printf("%c",s[i]);
    }
    printf("\n");
    return process(s,len,res,start,end);
}