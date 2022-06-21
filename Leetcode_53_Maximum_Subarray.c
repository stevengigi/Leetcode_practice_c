#include<stdio.h>
//Leetcode_53. Maximum Subarray
//Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//A subarray is a contiguous part of an array.
//
//Example 1:
//Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
//Output: 6
//Explanation: [4,-1,2,1] has the largest sum = 6.
//
//Example 2:
//Input: nums = [1]
//Output: 1


//nums:[-2,1,-3,4,-1,2,1,-5,4]
// f_f:[-2,1,-2,4, 3,5,6, 1,5]
//		  -1	2
//nums:[-6,-3,-4,-5]
// f_f:[-6,-3,-4,-5]
int maxSubArray(int* nums, int numsize){
	int f[numsize];
	f[0]=nums[0];
	int max=f[0];
	if(numsize==1) return nums[0]; 
	for(int i=1;i<numsize;i++){
		f[i]=nums[i]+f[i-1];
		if(f[i-1]<0  && nums[i]>f[i]){ //f[i-1]<0 §PÂ_«e­±¬°­t  
			f[i]=nums[i];
		}
		if(f[i]>max){
			max=f[i];
		}
	}
	return max;
}

int main(){
	//int nums[]={-2,1,-3,4,-1,2,1,-5,4};
	int nums[]={-6,-3,-4,-5};
	printf("%d",maxSubArray(nums,sizeof(nums)/sizeof(int)));
}
