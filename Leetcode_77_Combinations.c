

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cal(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n*cal(n-1);
}

void backtrack(int n,int k,int **res,int *temp,int start,int index,int* returnSize, int** returnColumnSizes,int size){
    if(index==k){
        res[*returnSize]=(int*)malloc(sizeof(int)*k);
        memcpy(res[*returnSize],temp,k*sizeof(int));
        (*returnColumnSizes)[*returnSize]=k;
        (*returnSize)++;
    }else{
        for(int i=start;i<=n;i++){
            temp[index]=i;
            backtrack(n,k,res,temp,i+1,index+1,returnSize,returnColumnSizes,size);
            if(size==*returnSize){
                break;
            }
        }
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int size=cal(n)/(cal(k)*cal(n-k));
    printf("size : %d",size);
    *returnSize=0;
    *returnColumnSizes=(int*)malloc(sizeof(int)*size);
    int **res=(int **)malloc(sizeof(int*)*size);
    int *temp=(int*)calloc(k,sizeof(int));
    backtrack(n,k,res,temp,1,0,returnSize,returnColumnSizes,size);
    free(temp);
    return res;
}
