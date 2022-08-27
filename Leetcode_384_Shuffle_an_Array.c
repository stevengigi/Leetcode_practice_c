


typedef struct {
    int *array;
    int size;
    int *change;
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
    Solution *obj=(Solution*)malloc(sizeof(Solution));
    obj->array=(int*)malloc(sizeof(int)*numsSize);
    obj->change=(int*)malloc(sizeof(int)*numsSize);
    obj->size=numsSize;
    // memcpy(solution->original, nums, sizeof(int) * size);
    memcpy(obj->array, nums, sizeof(int) * obj->size);
    memcpy(obj->change, nums, sizeof(int) * obj->size);
    return obj;
}

int* solutionReset(Solution* obj, int* retSize) {
    *retSize=obj->size;
    return obj->array;
}

int* solutionShuffle(Solution* obj, int* retSize) {
    *retSize=obj->size;
    for(int i=0;i<obj->size;i++){
        int temp=obj->change[i];
        int pos=rand()%obj->size;
        obj->change[i]=obj->change[pos];
        obj->change[pos]=temp;
    }
    return obj->change;
}

void solutionFree(Solution* obj) {
    free(obj->array);
    free(obj->change);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);

 * int* param_2 = solutionShuffle(obj, retSize);

 * solutionFree(obj);
*/