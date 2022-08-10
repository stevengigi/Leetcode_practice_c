#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int quicksort(int *nums,int low,int high,int k){
    int pivot=nums[high];
    int p=low;
    for(int i=low;i<=high-1;i++){
        if(nums[i]<=pivot){
            swap(&nums[p],&nums[i]);
            p++;
        }
    }

    swap(&nums[high],&nums[p]);
    // printf("\n i: %d\n",p);
    if(p > k) return quicksort(nums,low,p-1,k);
    else if(p < k) return quicksort(nums,p+1,high,k);
    else return nums[p];
}
void display(int *nums,int size){
    for(int i=0;i<size;i++){
        printf(" %d ",nums[i]);
    }
    printf("\n");
}
int findKthLargest(int* nums, int numsSize, int k){
    k=numsSize-k;
    int a=(quicksort(nums,0,numsSize-1,k));
    display(nums,numsSize);
    return a;
}

int main(){
    int nums[6]={3,2,1,5,6,4};
    printf("%d",findKthLargest(nums,sizeof(nums)/sizeof(nums[0]),2));
}