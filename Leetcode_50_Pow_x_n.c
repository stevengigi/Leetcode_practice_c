#include<stdio.h>
#include<stdlib.h>

double dfs(double x, long long l) {
    if (l == 0) return 1;
    if (l % 2 == 0) return dfs(x, l / 2) * dfs(x, l / 2);
    else return dfs(x, l / 2) * dfs(x, l / 2) * x;
}

double myPow(double x, int n){
    long long l = (long long)n;
    if (l < 0) {
        l = -l;
        x = 1/x;
    }
    return dfs(x, l);
}

int main(){
    double x=5.2;
    int n=5;
    printf("%f\n",myPow(x,n));
}