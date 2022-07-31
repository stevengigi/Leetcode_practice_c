#include<stdio.h>
#include<stdlib.h>
//O(M) :matrix cell
//O(1) :space
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int left=0;
    int right=matrixSize-1;
    while(left<=right){
        int top=left;
        int buttom=right;
        for(int i=0;i<(right-left);i++){
            // 儲存左上角的值
            int topleft=matrix[top][left+i];

            // 左上角的值 換成 左下角的值
            matrix[top][left+i]=matrix[buttom-i][left];

            // 左下角的值換成 右下角的值
            matrix[buttom-i][left]=matrix[buttom][right-i];

            // 右下角的值 換成 右上角的
            matrix[buttom][right-i]=matrix[top+i][right];

            //右上角的值 換成 左上角的
            matrix[top+i][right]=topleft;
        }
        right--;
        left++;
    }
}

int main(){
    int size=5;
    int  **c =(int**)malloc(sizeof(int*)*size);
    for(int i=0;i<size;i++){
        c[i]=(int*)malloc(sizeof(int)*size);
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            c[i][j]=(i+1)*(j+1);
        }
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf(" %3d ",c[i][j]);
        }
        printf("\n\n");
    }
    int *p[size];
    for(int i=0;i<size;i++){
        p[i]=&c[i][0];
    }
    rotate(p,size,&size);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf(" %3d ",c[i][j]);
        }
        printf("\n");
    }
}