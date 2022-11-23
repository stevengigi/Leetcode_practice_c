int cmp(const int *a,const int *b){
    return *a-*b;
}

int triangleNumber(int* nums, int numsSize){
    int count=0;
    qsort(nums,numsSize,sizeof(int),cmp);
    for(int i=0;i<numsSize-2;i++){
        int k=i+2;
        for(int j=i+1;j<numsSize-1&&nums[i]!=0;j++){
            while(k<numsSize &&nums[i]+nums[j]>nums[k]){
                k++;
            }
            // printf(" i : %d | j : %d | k : %d\n",i,j,k);
            count+=k-j-1;
        }
    }
    return count;
}