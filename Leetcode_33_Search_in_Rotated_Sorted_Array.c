//Leetcode_33_Search in Rotated Sorted Array
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int removeDuplicates(int*, int);
void shiftint(int*,int,int,int);
void reverse(int*,int,int);
int search(int*,int,int);
int cmp(const void* a,const void* b){
	return *(int *)a - *(int *)b;  // 小排到大 
}

typedef  struct number{
	int *number;
	int size;
}number;

int main(){
	number list;	
	list.number = (int*)malloc(10*sizeof(int));
	list.size=10;
	unsigned int seed;
	seed = time(NULL);
	srand(seed); // 以時間序列當亂數種子
	printf("number_size : %d \n",list.size);
	//隨機產生整數數列 
	printf("number[] : ");
	for(int i=0; i<list.size; ++i){
		list.number[i]=rand()%10;
		printf("%d ",list.number[i]);
	}
	
	//	void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
	qsort(list.number,list.size,sizeof(int) ,cmp);
	printf("\nAfter Sort : ");
	for(int i=0; i<list.size; ++i){
		printf("%d ",list.number[i]);
	}
	// delete duplicate number
	// [0 1 1 2 3 4 4 5 8 10]
	//  ^
	//    ^
	// [0 1 2 3 4 5 8 10 x x]
	
	int size=removeDuplicates(list.number,list.size);
	
	list.number=(int*)realloc(list.number,sizeof(int)*(size+1));
	list.size=size;
	printf("\nnew size:%d",size);
	printf("\nDelete Duplicate space: ");
	for(int i=0; i<list.size; ++i){
		printf("%d ",list.number[i]);
	}

	int shift=rand()% size;
	int direction =rand()% 2;
	printf("\nshift : %d",shift);
	// 0 left 、 1 right
	printf("\ndirection : %d | 0:left 1:right",direction);
	shiftint(list.number,list.size,shift,direction);
	printf("\nAfter shift: ");
	for(int i=0; i<list.size; ++i){
		printf("%d ",list.number[i]);
	}
	int target=5;
	printf("\nPosition : %d",search(list.number,list.size,target));
	
}

void shiftint(int*number,int size,int shift,int direction){
	if(direction==1)
		shift=size-shift;
	reverse(number,0,shift);
	reverse(number,shift,size);
	reverse(number,0,size);
} 
void reverse(int*number,int start,int end){
	end--;
	while(start<end){
		int temp=number[start];
		number[start]=number[end];
		number[end]=temp;
		start++;
		end--;
	}
}
int removeDuplicates(int* nums, int numsSize){
	int last=0;	
	for(int i=1;i<numsSize;i++){
		if(nums[i]!=nums[i-1]){
			last++;
			nums[last]=nums[i];
		}	
	}
	printf("\nDelete Duplicate : ");
	for(int i=0; i<last+1; ++i){
		printf("%d ",nums[i]);
	}
	return last+1;
} 
int search(int* nums, int numsSize, int target){
	int left=0;
	int right=numsSize-1;
	int mid;
	while(left<=right){
		mid=(left+right)/2;
		if(target==nums[mid]){
			return mid;
		}
		if(nums[mid]<target){
			if(nums[mid]>=nums[left]){
				left=mid+1;
			}
			else{
				if(target>=nums[left]){
					right=mid;
				}
				else{
					left=mid+1;
				}
			}
		}
		else if(nums[mid]>target){	
			if(nums[mid]>=nums[left]){
				if(target>=nums[left]){
					right=mid;
				}
				else{
					left=mid+1;
				}
			}
			else{
				right=mid-1;
			}
		}
	}
	
	return -1;
}
