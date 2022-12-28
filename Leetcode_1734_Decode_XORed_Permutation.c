/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* decode(int* encoded, int encodedSize, int* returnSize){
    int *arr=(int*)malloc(sizeof(int)*(encodedSize+1));
    *returnSize=encodedSize+1;
    int first=(encodedSize+1)^encodedSize;
    for(int i=0;i<encodedSize;i++){
        first^=i;
        if(i%2==1){
            first^=encoded[i];
        }
    }
    printf("first : %d",first);
    arr[0]=first;
    for(int i=1;i<=encodedSize;i++){
        arr[i]=encoded[i-1]^arr[i-1];
    }
    return arr;
}