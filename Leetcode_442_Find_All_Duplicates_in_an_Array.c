/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    *returnSize=0;
    int *res=(int*)malloc(sizeof(int)*(numsSize/2));
    int *table=(int*)calloc((numsSize+1),sizeof(int));
    for(int i=0;i<numsSize;i++){
        table[nums[i]]++;
        if(table[nums[i]]==2){
            res[(*returnSize)++]=nums[i];
        }
    }
    free(table);
    return res;
}