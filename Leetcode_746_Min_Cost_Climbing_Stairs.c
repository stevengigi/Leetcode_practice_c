#include<stdio.h>
#include<stdlib.h>

int min(int a,int b){
    return (a>b)? b : a;
}

int dp(int *m,int *cost,int i){
    if(i<=1){
        return cost[i];
    }
    if(m[i]>0) return m[i];
    return m[i]=min(dp(m,cost,i-1),dp(m,cost,i-2))+cost[i];
}

int minCostClimbingStairs(int* cost, int costSize){
    int *m=(int*)calloc(costSize,sizeof(int));
    int ans=min(dp(m,cost,costSize-2),dp(m,cost,costSize-1));
    // printf(" m : ");
    // for(int i=0;i<costSize;i++){
    //     printf(" %d ",m[i]);
    // }
    // printf("\n");
    free(m);
    return ans;
}

int minCostClimbingStairs2(int* cost, int costSize){
    int *a=(int*)calloc(costSize,sizeof(int));
    a[0]=cost[0];
    a[1]=cost[1];
    for(int i=2;i<costSize;i++){
        a[i]=min(a[i-1],a[i-2])+cost[i];
    }
    // printf(" a : ");
    // for(int i=0;i<costSize;i++){
    //     printf(" %d ",a[i]);
    // }
    // printf("\n");
    return min(a[costSize-1],a[costSize-2]);
}

int main(){
    int cost[12]={1,2,3,4,5,6,7,8,9,10,11,12};
    printf(" %d \n",minCostClimbingStairs(cost,sizeof(cost)/sizeof(int)));
    printf(" %d \n",minCostClimbingStairs2(cost,sizeof(cost)/sizeof(int)));
}