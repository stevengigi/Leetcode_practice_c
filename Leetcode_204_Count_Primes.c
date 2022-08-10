#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int countPrimes(int n){
    int count=0, i;
    bool *nums = (bool*)calloc(n,sizeof(bool)); // all false
    for(i = 2 ; i*i<=n ; i++)
    {
        if(!nums[i]){
            for(int j = i*i ; j<n ; j+=i){
                nums[j] = true;
            }
        }
    }
    for(i = 2 ; i < n ; i++){
        if(!nums[i]) count++;
    }
    free(nums);
    return count;
}

int main(){
    printf(" %d ",countPrimes(20));
}