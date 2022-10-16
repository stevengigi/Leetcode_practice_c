

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
    *returnSize=n+1;
    int *res=(int*)calloc(*returnSize,sizeof(int));
    res[0]=0;
    for(int i=1;i<=n;i++){
        if(!(i&(i-1))){
          res[i]=1;
            continue;
        }
        int replace=i;
        int count=0;
        while(replace){
            replace=replace&(replace-1);
            count++;
        }
        res[i]=count;
    }
    return res;
}