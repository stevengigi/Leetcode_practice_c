char *IntToChar(int n){
    char *temp=(char*)malloc(sizeof(char)*11);
    temp[10]='\0';
    int index=9;
    while(n){
        temp[index]=n%10+'0';
        n/=10;
        index--;
    }
    return &temp[index+1];
}

char * countAndSay(int n){
    if(n==1){
        return "1";
    }
    char *ans=(char*)malloc(sizeof(char)*5000);
    char *post=(char*)malloc(sizeof(char)*5000);
    ans[0]='1';
    ans[1]='\0';



    for(int i=2;i<=n;i++){

        int pos=0;
        int anslen=strlen(ans);
        int count=1;
        char *temp;

        for(int j=1;j<anslen;j++){
            if(ans[j]==ans[j-1]){
                count++;
            }else{
                temp=IntToChar(count);
                strncpy(&post[pos],temp,strlen(temp));
                pos+=strlen(temp);
                post[pos]=ans[j-1];
                pos++;
                count=1;
            }
        }
        temp=IntToChar(count);
        strncpy(&post[pos],temp,strlen(temp));
        pos+=strlen(temp);
        post[pos++]=ans[anslen-1];
        post[pos]='\0';
        /*---- swap ---*/
        temp=ans;
        ans=post;
        post=temp;
        printf("i : %d | s :%s\n",i,ans);
    }
    free(post);
    return ans;

}