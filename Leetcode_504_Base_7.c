int len(int num){
    int ans=0;

    while(num!=0){
        num/=7;
        ans++;
    }
    return ans+1;
}

char * convertToBase7(int num){
    if(num==0) return "0";
    int length=len(num);
    printf("length : %d\n",length);
    printf("root : %d\n",length);
    int root=length-2;
    int flag=0;
    int index=0;
    if(num < 0){
        length++;
        flag=1;
        num*=-1;
    }
    char *res=(char*)malloc(sizeof(char)*length);
    memset(res,0,length);
    if(flag) res[index++]='-';
    printf("length : %d\n",length);
    // index=0;
    while(num!=0){
        int poww=pow(7,root);
        printf(" poww : %d",poww);
        int temp=num/poww;
        num=num%poww;
        // printf(" %c ",res[index]);
        res[index++]=temp+'0';
        printf("  index : %d",index);
        root--;
    }
    while(index!=length-1){
        res[index++]='0';
    }
    return res;
}