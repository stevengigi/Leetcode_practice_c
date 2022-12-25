/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
// 1 3 7 12
int findvalue(int *arr,int size,int val){
    int left=0;
    int right=size-1;
     printf("----ok----\n");
    while(left<right){
        int mid=(right-left)/2+left;
        if(arr[mid]>val){
            right=mid-1;
        }else if(arr[mid]<val){
            left=mid+1;
        }else {
            return mid+1;
        }
    }
    // printf("size : %d\n",left);
    if(arr[left]<=val){
        return left+1;
    }else{
        return left;
    }
}

int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize){
    qsort(nums,numsSize,sizeof(int),cmp);
    int prefix[numsSize];
    prefix[0]=nums[0];
    for(int i=1;i<numsSize;i++){
        prefix[i]=prefix[i-1]+nums[i];
    }

    int *res=(int*)malloc(sizeof(int)*queriesSize);
    *returnSize=queriesSize;
    for(int i=0;i<queriesSize;i++){
        res[i]=findvalue(prefix,numsSize,queries[i]);
        printf("res[i] : %d \n",res[i]);
    }
    return res;
}