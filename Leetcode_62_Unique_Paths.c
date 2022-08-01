#include<stdio.h>
#include<stdlib.h>
//  m=3 n=2
//  x  1
//  2  1
//  1  o
//  => 1+2=3
int uniquePaths(int m, int n){
    int matrix[m][n];
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i==m-1){
                matrix[i][j]=1;
                continue;
            }
            if(j==n-1){
                matrix[i][j]=1;
                continue;
            }
            matrix[i][j]=matrix[i+1][j]+matrix[i][j+1];
        }
    }
    return matrix[0][0];
}

int main(){
    printf("%d",uniquePaths(3,2));
}