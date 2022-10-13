

void duplicateZeros(int* arr, int arrSize){
    int *res=(int*)calloc(arrSize*2,sizeof(int));
    int index=0;
    for(int i=0;i<arrSize;i++){
        if(arr[i]==0){
            index+=2;
        }else{
            res[index++]=arr[i];
        }
    }
    for(int i=0;i<arrSize;i++){
        arr[i]=res[i];
    }
    free(res);
}