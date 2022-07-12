#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<time.h>
int nums[10]={0,0,0,0,0,1,1,1,1,1};
bool isBadVersion(int version){
    if(nums[version])
        return true;
    else
        return false;
}

int firstBadVersion(int n) {
    int left=0;
    int right=n;
    int mid;
    while(left<right){
        mid=(right-left)/2+left;
        if(isBadVersion(mid)){
            right=mid;
        }else{
            left=mid+1;
        }
    }
    return left;
}
int main(){
    printf("%d",firstBadVersion(sizeof(nums)/sizeof(int)));
}