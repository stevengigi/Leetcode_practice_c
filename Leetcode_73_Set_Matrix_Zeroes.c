#include<stdio.h>
#include<stdlib.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int *col=(int*)calloc(*matrixColSize,sizeof(int));
    int *row=(int*)calloc(matrixSize,sizeof(int));
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<*matrixColSize;j++){
            if(matrix[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<*matrixColSize;j++){
            if(row[i]==1 || col[j]==1){
                matrix[i][j]=0;
            }
        }
    }
}

int main(){
    int nums[3][3]={{1,1,1},{1,0,1},{1,1,1}};
    int *p[3]={&nums[0][0],&nums[1][0],&nums[2][0]};
    int matrixColSize=3;
    setZeroes(p,3,&matrixColSize);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf(" %d ",nums[i][j]);
        }
        printf("\n");
    }
}