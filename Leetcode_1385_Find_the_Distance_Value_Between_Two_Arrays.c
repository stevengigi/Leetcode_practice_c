#include<stdio.h>
#include<stdlib.h>

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d){
    int ans=arr1Size;
    for(int i=0;i<arr1Size;i++){
        for(int j=0;j<arr2Size;j++){
            if(abs(arr1[i]-arr2[j])<=d){
                ans--;
                break;
            }
        }
    }
    return ans;
}

int main(){
    int arr1[4]={2,1,100,3};
    int arr2[5]={-5,-2,10,-3,7};
    printf(" %d \n",findTheDistanceValue(arr1,sizeof(arr1)/sizeof(int),arr2,sizeof(arr2)/sizeof(int),2));
}