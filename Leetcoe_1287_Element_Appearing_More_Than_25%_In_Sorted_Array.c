

int findSpecialInteger(int* arr, int arrSize){
    int size=arrSize/4;
    // int index=1;
    for(int i=0;i<arrSize-1;i++){
        if(arr[i]== arr[i+size])  return arr[i];
    }
    return arr[0];
}