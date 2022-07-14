#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool checkIfExist(int* arr, int arrSize){
    for(int i=0;i<arrSize;i++){
        for(int j=0;j<arrSize;j++){
            if(i==j){
                continue;
            }
            if(arr[i]==2*arr[j]){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int arr[12]={1,7,9,2,6,15,13,12,51,48,17,19};
    printf("%d\n",checkIfExist(arr,sizeof(arr)/sizeof(int)));
}