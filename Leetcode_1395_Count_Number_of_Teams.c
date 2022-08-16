#include<stdio.h>
#include<stdlib.h>
int numTeams(int* rating, int ratingSize){
    // itn *left=(int*)calloc(2,sizeof(int));
    // int *right=(int*)calloc(2,sizeof(int));
    int res=0;
    for(int i=1;i<ratingSize;i++){
        int left[2]={0}; //[small big]
        int right[2]={0}; //[big small]
        for(int j=0;j<ratingSize;j++){
            if(i>j){
                if(rating[i]>rating[j]){
                    left[0]++;
                }else if(rating[i]<rating[j]){
                    left[1]++;
                }
            }else if(i<j){
                if(rating[i]>rating[j]){
                    right[1]++;
                }else if(rating[i]<rating[j]){
                    right[0]++;
                }
            }
        }
        res+=left[0]*right[0]+left[1]*right[1];
    }
    return res;
}
int main(){
    int nums[5]={2,5,3,4,1};
    printf("%d",numTeams(nums,sizeof(nums)/sizeof(nums[0])));
}