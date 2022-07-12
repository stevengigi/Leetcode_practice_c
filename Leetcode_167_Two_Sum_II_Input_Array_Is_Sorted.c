#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int l=0;
    int r=numbersSize-1;
    int *res=(int*)malloc(sizeof(int)*2);
    *returnSize=2;
    while(true){
        int sum=numbers[l]+numbers[r];
        if(sum==target){
            res[0]=l+1;
            res[1]=r+1;
            return res;
        }
        if(sum < target){
            l++;
        }else{
            r--;
        }
    }
    return res;
}

// Binary Search
int* twoSum2(int* numbers, int numbersSize, int target, int* returnSize){
    int *res=(int*)malloc(sizeof(int)*2);
    *returnSize=2;
    for(int i=0;i<numbersSize;i++){
        int l=i+1;
        int r=numbersSize-1;
        int find=target-numbers[i];
        int mid;
        while(l<=r){
            mid=(r-l)/2+l;
            if(numbers[mid]==find){
                res[0]=i+1;
                res[1]=mid+1;
                return res;
            }
            if(numbers[mid]<find){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
    }
    return res;
}


int main(){
    int numbers[4] = {2,7,11,15};
    int target = 9;
    int returnsize;
    int *p;
    p=twoSum(numbers, sizeof(numbers)/sizeof(int),target,&returnsize);
    for(int i=0;i<returnsize;i++){
        printf(" %d ",p[i]);
    }
    p=twoSum2(numbers, sizeof(numbers)/sizeof(int),target,&returnsize);
    for(int i=0;i<returnsize;i++){
        printf(" %d ",p[i]);
    }
}