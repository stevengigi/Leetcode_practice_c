/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* sumOfThree(long long num, int* returnSize){
    long long *res;
    if(num%3==0){
        *returnSize=3;
        res=malloc(sizeof(long long)*3);
        res[0]=num/3-1;
        res[1]=num/3;
        res[2]=num/3+1;

    }else *returnSize=0;
    return res;

}