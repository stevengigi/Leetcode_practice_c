

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    *returnSize=num_people;
    int *res=(int*)calloc(num_people,sizeof(int));
    int index=0;
    int nums=0;
    while(candies > 0){
        index=index%num_people;
        if(candies <= nums){
            res[index]+=candies;
            break;
        }
        res[index++]+=++nums;
        candies=candies-nums;
    }
    return  res;
}