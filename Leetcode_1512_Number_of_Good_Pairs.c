

int numIdenticalPairs(int* nums, int numsSize){
    int *table=(int*)calloc(101,sizeof(int));
    int res=0;
    for(int i=0;i<numsSize;i++){
        res+=table[nums[i]]++;
    }
    free(table);
    return res;
}