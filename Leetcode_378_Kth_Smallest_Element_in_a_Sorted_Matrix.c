#include<stdio.h>
#include<stdlib.h>

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    int low=matrix[0][0];
    int high=matrix[*matrixColSize-1][*matrixColSize-1];
    int count=0;
    int mid;
    while(low<high){
        mid=(high-low)/2+low;
        count=0;
        for(int i=0 , j=*matrixColSize-1;i<*matrixColSize;i++){
            while(j>=0 && matrix[i][j]>mid){
                j--;
            }
            count+=(j+1);
        }
        if(count<k){
            low=mid+1; // 因為count < k 所以要找的數一定比 mid 大
        }else{
            high=mid; // 因為 count >=k 所以要找的數 可能等於mid 本身或更小的數
        }
    }
    return low;
}

int main(){
    int matrix[3][3]={{1,2,3},{2,4,6},{3,6,9}};
    int *p[3]={&matrix[0][0],&matrix[1][0],&matrix[2][0]};
    int matrixcolsize=3;
    printf(" %d ",kthSmallest(p,3,&matrixcolsize,4));
}