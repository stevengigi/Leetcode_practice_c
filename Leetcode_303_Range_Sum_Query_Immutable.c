


typedef struct {
    int *arr;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *obj=(NumArray*)malloc(sizeof(NumArray));
    obj->arr=(int*)calloc((numsSize+1),sizeof(nums[0]));
    for(int i=1;i<numsSize+1;i++){
        obj->arr[i]=nums[i-1]+obj->arr[i-1];
        printf("obj->arr[%d] : %d \n",i,obj->arr[i]);
    }
    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    if(left==0) return obj->arr[right+1];
    return obj->arr[right+1]-obj->arr[left];
}

void numArrayFree(NumArray* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);

 * numArrayFree(obj);
*/