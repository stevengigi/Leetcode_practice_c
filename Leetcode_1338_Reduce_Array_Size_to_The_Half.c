#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}

int minSetSize(int* arr, int arrSize){
    qsort(arr,arrSize,sizeof(int),cmp);
    int *frequency=(int*)calloc(arrSize,sizeof(int));
    int cnt=1;
    int index=0;
    frequency[index]=cnt;
    for(int i=1;i<arrSize;i++){
        if(arr[i] == arr[i-1]){
            ++cnt;
            frequency[index]=cnt;
        }else{
            cnt=1;
            frequency[++index]=cnt;
        }
    }
    qsort(frequency,arrSize,sizeof(int),cmp);
    for(int i=0;i<arrSize;i++){
        printf(" %d ",frequency[i]);
    }
    cnt=0;
    int res=1;
    while(cnt<arrSize/2){
        cnt+=frequency[arrSize-res];
        ++res;
    }
    free(frequency);
    return res-1;
}

int main(){
    int nums[8]={3,3,3,3,2,2,2,1};
    printf("\n%d",minSetSize(nums,sizeof(nums)/sizeof(nums[0])));
}