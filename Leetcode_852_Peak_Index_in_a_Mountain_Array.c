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
    int arr[10]={24,69,100,99,79,78,67,36,26,19};
    printf("peakIndexInMountainArray : %d\n",peakIndexInMountainArray(arr,sizeof(arr)/sizeof(int)));

}