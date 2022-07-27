#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
int hammingWeight(uint32_t n) {
    int count=0;
    while(n){
        if(n&1==1)
            count++;
        n=n>>1;
        // printf("%lu\n",n);
    }
    return count;
}

int main(){
    uint32_t b=18;
    printf("%d\n",hammingWeight(b));
}