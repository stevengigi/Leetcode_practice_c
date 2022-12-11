/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* circularPermutation(int n, int start, int* returnSize){
    *returnSize=pow(2,n);
    int *res=(int*)malloc(sizeof(int)*(*returnSize));
    // res[0]=start;
    for(int i=0;i<*returnSize;i++){
        res[i]=start ^ i ^ (i>>1);
    }
    for(int i=1;i<*returnSize;i++){
        printf(" %d ",res[i]);
    }
    return res;
}