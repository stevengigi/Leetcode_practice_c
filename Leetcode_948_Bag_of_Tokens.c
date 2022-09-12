int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}

int bagOfTokensScore(int* tokens, int tokensSize, int power){
    if(tokensSize==0) return 0;
    qsort(tokens,tokensSize,sizeof(int),cmp);
    for(int i=0;i<tokensSize;i++){
        printf(" %d ",tokens[i]);
    }
    printf("\n");
    int left=0,right=tokensSize-1,res=0;
    while(left<right){

        if(tokens[left] <= power){
            power-=tokens[left++];
            res++;
        }else{
            if(res==0) break;
            power+=tokens[right--];
            res--;
        }
        printf("power %d  res : %d  left : %d  right : %d\n",power,res,left,right);
    }
    if(power>=tokens[left]) res++;
    return res;
}