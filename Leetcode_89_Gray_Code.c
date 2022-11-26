/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize){
    int size=pow(2,n);
    printf("size : %d\n",size);
    *returnSize=size;
    int *res=(int*)malloc(sizeof(int)*size);
    res[0]=0;
    res[1]=1;
    int index=2;
    for(int i=1;i<n;i++){
        int temp=1;
        printf("coming in \n");
        for(int j=index;j<index*2;j++){
            res[j]=res[j-temp] | (1<<i);
            printf(" %d ",res[j]);
            temp=(j-index+1)*2+1;
        }
        index*=2;
    }

    return res;
}

// 0 1 3 2 6 7 5 4