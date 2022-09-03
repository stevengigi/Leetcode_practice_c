

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct table{
    int ele;
    int count;
};

int cmp(const void*a ,const void *b){
    return *(int*)a-*(int*)b;
}

int cmptable(const void *a,const void *b){
    struct table *aa=( struct table *)a;
    struct table *bb= (struct table *)b;
    return bb->count-aa->count;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    *returnSize=0;
    if(numsSize==0){
        return NULL;
    }
    int index=0;
    qsort(nums,numsSize,sizeof(int),cmp);
    struct table *ht=(struct table*)malloc(sizeof(struct table)*numsSize);
    printf("ok\n");
    ht[index].ele=nums[0];
    ht[index].count=1;

    for(int i=1;i<numsSize;i++){
        if(nums[i]!=nums[i-1]){
            index++;
            ht[index].ele=nums[i];
            ht[index].count=1;
        }else if(nums[i]==nums[i-1]){
            ht[index].count++;
        }
    }
    qsort(ht,index+1,sizeof(struct table),cmptable);
    int *res=(int*)malloc(sizeof(int)*k);
    for(int i=0;i<k;i++){
        res[i]=ht[i].ele;
    }
    *returnSize=k;
    free(ht);
    return res;
}