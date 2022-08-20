#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return (a>b)?a:b;
}

int minRefuelStops(int target, int startFuel, int** stations, int stationsSize, int* stationsColSize){
    int *dp=(int*)calloc(stationsSize+1,sizeof(int));
    dp[0]=startFuel;
    for(int i=0;i<stationsSize;i++){
        for(int j=i;j>=0;j--){
            if(dp[j]>=stations[i][0]){
                dp[j+1]=max(dp[j+1],dp[j]+(long)stations[i][1]);
            }
        }
    }
    for(int i=0;i<=stationsSize;i++){
        if(dp[i]>=target) return i;
    }
    return -1;
}

int main(){
    int target=100;
    int startFuel=50;
    int station[2][2]={{10,10},{50,60}};
    int *p[2]={&station[0][0],&station[1][0]};
    int colsize=2;
    printf("%d",minRefuelStops(target,startFuel,p,2,&colsize));
}