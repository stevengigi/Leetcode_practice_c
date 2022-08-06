#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int poorPigs(int buckets, int minutesToDie, int minutesToTest){
    // Total Rounds (T) = totalTime/poisonTime
    // Assume p = no of pigs that will give us the result
    // Therefore, (T+1)^p >= buckets
    // Taking log on both sides, p = log(buckets)/log(T+1);
    // Return ceil of p
    return ceil(log(buckets)/log(minutesToTest/minutesToDie+1));
}

int main(){
    printf("%d",poorPigs(4,2,4));
}
