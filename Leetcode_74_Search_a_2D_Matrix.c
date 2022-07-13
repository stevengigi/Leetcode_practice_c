#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//Binary Search
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row=matrixSize;
    int col=*matrixColSize;
    int end=row*col-1;
    int begin=0;
    int mid;
    while(begin<=end){
        mid=(end-begin)/2+begin;
        int num=matrix[mid/col][mid%col];
        if(num==target){
            return true;
        }else if(num < target){
            begin=mid+1;
        }else{
            end=mid-1;
        }
    }
    return false;

}
//Array
bool searchMatrix2(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row=0;
    int col=*matrixColSize - 1;
    while(row<matrixSize && col >-1){
        int num=matrix[row][col];
        if(num==target){
            return true;
        }else if(num < target){
            row++;
        }else{
            col--;
        }
    }
    return false;
}

int main(){
    int matrix[3][4]={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    int *p[3]={matrix[0],matrix[1],matrix[2]};
    int matrixcol=sizeof(matrix[0])/sizeof(int);
    printf(" %d \n",searchMatrix(p,sizeof(matrix)/sizeof(matrix[0]),&matrixcol,target));
    printf(" %d \n",searchMatrix2(p,sizeof(matrix)/sizeof(matrix[0]),&matrixcol,target));
}