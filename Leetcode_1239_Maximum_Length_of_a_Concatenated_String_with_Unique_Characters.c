

int max(int a,int b){
    return (a>b)?a:b;
}

void backtrack(char **arr,int *temp,int arrSize,int combine,int pos,int *ans,int len){
    if(pos >= arrSize){
        return;
    }
    // if((temp[pos]&combine)!=0){
    //     return;
    // }
    printf("pos : %d\n",pos);
    int copy=combine;
    for(int i=pos;i<arrSize;i++){
        if((temp[i]&combine)!=0){
            printf("& is not zero\n");
            continue;
        }

        combine= (combine|temp[i]);
        len+=strlen(arr[i]);
        *ans=max(*ans,len);
        printf("ans : %d \n",*ans);
        backtrack(arr,temp,arrSize,combine,i+1,ans,len);
        combine=copy;
        len-=strlen(arr[i]);
    }
}

int maxLength(char ** arr, int arrSize){

    int *ans=(int*)calloc(1,sizeof(int));
    int *temp=(int*)calloc(arrSize,sizeof(int));
    for(int i=0;i<arrSize;i++){
        int lenmax=0;
        for(int j=0;j<strlen(arr[i]);j++){
            int index=1<<(arr[i][j]-'a');
            if((temp[i]&index)!=0){
                lenmax=0;
                temp[i]=INT_MAX;
            }
            else{
                lenmax++;
                temp[i] += index;
            }
        }
        *ans=max(*ans,lenmax);
    }
    if(arrSize==1) return *ans;
    printf("ans : %d\n",*ans);
    int combine =0;
    for(int i=0;i<arrSize;i++){
        printf("arr : %s\n",arr[i]);
        combine=temp[i];
        backtrack(arr,temp,arrSize,combine,i+1,ans,strlen(arr[i]));
    }
    free(temp);
    return *ans;
}