#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int peakIndexInMountainArray(int* arr, int arrSize){
    if(arrSize==3){
        return 1;
    }
    int m=arrSize/2;
    while(true){
        if(arr[m] >arr[m+1] && arr[m] >arr[m-1]){
            return m;
        }else if(arr[m]<arr[m-1]){
            m=m-1;
        }else{
            m=m+1;
        }
    }
}

int main(){
    int arr[5]={0,4,3,2,1};
    printf("peakIndexInMountainArray : %d",peakIndexInMountainArray(arr,sizeof(arr)/sizeof(int)));
}