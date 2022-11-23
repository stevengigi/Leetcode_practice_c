/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** mergeSimilarItems(int** items1, int items1Size, int* items1ColSize, int** items2, int items2Size, int* items2ColSize, int* returnSize, int** returnColumnSizes){
    int arr[1001]={0};
    for(int i=0;i<items1Size;i++){
        arr[items1[i][0]]+=items1[i][1];
    }
    for(int i=0;i<items2Size;i++){
        arr[items2[i][0]]+=items2[i][1];
    }
    int **res=(int**)malloc(sizeof(int*)*(items1Size+items2Size));


    int size=0;
    for(int i=0;i<1001;i++){

        if(arr[i]){
            res[size]=(int*)malloc(sizeof(int)*2);
            res[size][0]=i;
            res[size][1]=arr[i];

            size++;
        }
    }
    // res=(int**)realloc(res,size);

    *returnSize=size;
    *returnColumnSizes=(int*)malloc(sizeof(int)*(size));
    printf("----------ok-------");
    for(int i=0;i<size;i++){
        (*returnColumnSizes)[i]=2;
    }


    return res;
}