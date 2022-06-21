//Leetcode_27_Remove Element
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct list{
	int size;
	int* nums;
}list;

int removeElement(int* nums, int numsSize, int val){
	int k=-1;
	if(numsSize==0){
		return k;
	}
	for(int i=0;i<numsSize;i++){
		if(nums[i]!=val){
			k++;
			nums[k]=nums[i];
		}
	}
	nums=(int*)realloc(nums,sizeof(int)*k);
	return k+1;
}

int main(){
	list nums1;
	unsigned int seed = time(NULL);
	srand(seed);
	nums1.size=rand()%50;
	printf("\nsize: %d ",nums1.size);
	nums1.nums = (int*)malloc(sizeof(int)*nums1.size);
	printf("\n nums :");
	for(int i=0;i<nums1.size;i++){
		nums1.nums[i]=rand()%11;
		printf(" %d ",nums1.nums[i]);
	}
	int val=rand()%11;
	printf("\n delete number: %d",val);
	int k=removeElement(nums1.nums,nums1.size,val);
	printf("\n k : %d",k);
	printf("\n After delete nums :");
	for(int i=0;i<k;i++){
		printf(" %d ",nums1.nums[i]);
	}
}
