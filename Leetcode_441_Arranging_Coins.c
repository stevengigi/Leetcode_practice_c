#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int arrangeCoins(int n){
//  1+2+3+...+x = n
// -> (1+x)x/2 = n
// -> x^2+x = 2n
// -> x^2+x+1/4 = 2n +1/4
// -> (x+1/2)^2 = 2n +1/4
// -> (x+0.5) = sqrt(2n+0.25)
// -> x = -0.5 + sqrt(2n+0.25)
    unsigned int a=n;
    int x=-0.5 + sqrt(2*a+0.25);
    return x;
}

int arrangeCoins2(int n){
    int i=0;
    int sum=0;
    while(sum<=n){
        i++;
        sum+=i;
    }
    return i-1;
}

int main(){
    printf(" %d\n",arrangeCoins(17));
    printf(" %d\n",arrangeCoins2(17));
}