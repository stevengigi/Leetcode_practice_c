//Leetcode_33_Search in Rotated Sorted Array
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int removeDuplicates(int*, int);
void shiftint(int*,int,int,int);
void reverse(int*,int,int);
int search(int*,int,int);
int cmp(const void* a,const void* b){
	return *(int *)a - *(int *)b;  // �p�ƨ�j
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
	srand(seed); // �H�ɶ��ǦC���üƺؤl
	printf("number_size : %d \n",list.size);
	//�H�����;�ƼƦC
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
	// 0 left �B 1 right
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
// 0　　1　　2　　 4　　5　　6　　7

// 7　　0　　1　　 2　　4　　5　　6

// 6　　7　　0　　 1　　2　　4　　5

// 5　　6　　7　　 0　　1　　2　　4

// 4　　5　　6　　7　　0　　1　　2

// 2　　4　　5　　6　　7　　0　　1

// 1　　2　　4　　5　　6　　7　　0
int search(int* nums, int numsSize, int target){
    int left=0;
    int right=numsSize-1;
    int mid;
    while(left<=right){
        mid=(right-left)/2+left;
        if(nums[mid]==target) return mid;
        if(nums[mid]<nums[right]){
            if(nums[mid]<target && nums[right]>=target)  left=mid+1;
            else right=mid-1;
        }
        else{
            if(nums[left]<=target && nums[mid]>target) right=mid-1;
            else left=mid+1;
        }
    }
    return -1;
}
