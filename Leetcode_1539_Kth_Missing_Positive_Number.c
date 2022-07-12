#include<stdio.h>
#include<stdlib.h>
// Brutal Force
int findKthPositive(int* arr, int arrSize, int k){
    int set=-1;
    int num=0;
    for(int j=0;j<arrSize;j++){
        if(j==0){
            for(int i=1;i<arr[j];i++){
                set++;
                if(set+1==k){
                    return i;
                }

            }
        }
        else{
            for(int i=1;i<arr[j]-arr[j-1];i++){
                set++;
                num=arr[j-1]+i;
                if(set+1==k){
                    return num;
                }
            }
        }

    }
    num=arr[arrSize-1]+k-set-1;
    return num;

}
// Binary search
int findKthPositive2(int* arr, int arrSize, int k){
    int left=0;
    int right=arrSize-1;
    int mid;
    while(left<=right){
        mid=(right+left)/2;
        if(arr[mid]-mid-1<k){
            left=mid+1;

        }else{
            right=mid-1;
            // return arr[right];
        }
    }
    return left+k;
    //   0   1   2   3   4   5   6   7   8  <-position
    //   2   3   4   7  11  13  15  17  19  <-arr
    //   1   1   1   3   6   7   8   9  10  <-多少沒插進去的數字的數量
}

int main(){
    int arr[9]={2,3,4,7,11,13,15,17,19};
    printf("%d\n",findKthPositive(arr,9,5));
    printf("%d\n",findKthPositive2(arr,9,5));
}