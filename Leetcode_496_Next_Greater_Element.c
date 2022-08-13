#include<stdio.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int temp[10001]={0};
    int *res=(int*)calloc(nums1Size,sizeof(int));
    *returnSize=nums1Size;
    int stack[nums2Size];
    int top=-1;
    for(int i=0;i<nums2Size;i++){
        while(top!=-1 &&stack[top]<nums2[i]){
            temp[stack[top]]=nums2[i];
            top--;
        }
        stack[++top]=nums2[i];
    }
    for(int j=0;j<nums1Size;j++){
        if(temp[nums1[j]]!=0){
            res[j]=temp[nums1[j]];
        }else{
            res[j]=-1;
        }
    }
    return res;
}

int main(){
    int nums1[3]={1,4,3};
    int nums2[5]={1,2,4,3,5};
    int size=0;
    int *p=nextGreaterElement(nums1,sizeof(nums1)/sizeof(int),nums2,sizeof(nums2)/sizeof(int),&size);
    for(int i=0;i<size;i++){
        printf(" %d ",p[i]);
    }
}