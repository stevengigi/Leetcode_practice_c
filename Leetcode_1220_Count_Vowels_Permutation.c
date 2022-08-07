#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// reference : https://www.youtube.com/watch?v=VUVpTZVa7Ls

int countVowelPermutation(int n){
    if(n==1){
        return 5;
    }
    int a=0;
    int e=1;
    int i=2;
    int o=3;
    int u=4;
    long long int dp[5][2]={{1,0},{1,0},{1,0},{1,0},{1,0}};
    // 會超過long long int range 所以對答案只需要對 mod 出來的數字就好
    int mode=pow(10,9)+7;
    for(int j=0;j<n-1;j++){
        dp[a][(j+1)%2]=(dp[e][j%2]+dp[i][j%2]+dp[u][j%2])%mode;
        dp[e][(j+1)%2]=(dp[a][j%2]+dp[i][j%2])%mode;
        dp[i][(j+1)%2]=(dp[e][j%2]+dp[o][j%2])%mode;
        dp[o][(j+1)%2]=(dp[i][j%2])%mode;
        dp[u][(j+1)%2]=(dp[i][j%2]+dp[o][j%2])%mode;
    }
    long long int sum=0;
    for(int i=0;i<5;i++){
        sum+=dp[i][(n+1)%2];
    }
    return sum%mode;
}

int main(){
    printf("%ld",countVowelPermutation(10));
}

