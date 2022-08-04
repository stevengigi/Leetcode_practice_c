#include<stdio.h>
#include<stdlib.h>
// node()代表有多少節點
// n=2 [1,2] => [root=1 ,2]=node(0)*node(1) + [1 ,root=2]=node(1)*node(0)
// 所以  [1,2]  = node(0)*node(1)+node(1)*node(0)
// n=3 [1,2,3] => [root=1 ,2,3]=node(0)*node(2) + [1 ,root=2,3]=node(1)*node(1) + [1 ,2,root=3]=node(2)*node(0)
// 所以  [1,2,3]  = node(0)*node(2)+node(1)*node(1)+node(2)*node(0)
// 以此類推

int numTrees(int n){
    if(n==1){
        return 1;
    }
    int *numstree=(int*)calloc(n+1,sizeof(int));
    numstree[0]=1;
    numstree[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            numstree[i]+=numstree[j]*numstree[i-j-1];
        }
    }
    return numstree[n];
}

int main(){
    printf("%d",numTrees(5));
}