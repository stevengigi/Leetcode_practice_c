#include<stdio.h>
#include<stdlib.h>

void merge(int *nums,int l,int m,int r){
    int i,j,k;
    int n1=m-l+1; //[l m]
    int n2=r-m; //[m+1 r]
    int L[n1];
    int R[n2];
    for(i=0;i<n1;i++){
        L[i]=nums[l+i];
    }
    for(j=0;j<n2;j++){
        R[j]=nums[m+j+1];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
        if(L[i]<R[j]){
            nums[k]=L[i];
            i++;
        }
        else{
            nums[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        nums[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        nums[k]=R[j];
        j++;
        k++;
    }

}
void mergesort(int *nums,int l,int r){
    if(l<r){
        int m=(r-l)/2+l;
        mergesort(nums,l,m);
        mergesort(nums,m+1,r);
        merge(nums,l,m,r);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize=numsSize;
    mergesort(nums,0,numsSize-1);
    return nums;
}

int main(){
    int nums[6]={6,5,4,3,2,1};
    for(int i=0;i<sizeof(nums)/sizeof(nums[0]);i++){
        printf(" %d",nums[i]);
    }
    printf("\n");
    int returnsize;
    int *p=sortArray(nums,sizeof(nums)/sizeof(nums[0]),&returnsize);
    for(int i=0;i<returnsize;i++){
        printf(" %d",p[i]);
    }
    printf("\n");

}