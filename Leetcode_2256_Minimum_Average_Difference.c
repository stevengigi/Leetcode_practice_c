
int minimumAverageDifference(int* nums, int numsSize){
    if(numsSize==1) return 0;
    long long *arr=(long long*)calloc(numsSize,sizeof(long long));
    arr[0]=nums[0];
    // printf(" %d ",arr[0]);
    for(int i=1;i<numsSize;i++){
        arr[i]=arr[i-1]+nums[i];
        // printf(" %d ",arr[i]);
    }
    printf("\n");
    int res=INT_MAX;
    int min;
    for(int i=0;i<numsSize;i++){
        int temp;
        if(i!=numsSize-1)   temp=(arr[numsSize-1]-arr[i])/(numsSize-1-i);
        else temp=0;
        int index=arr[i]/(i+1);
        int ans=abs(index-temp);
        // printf("index : %d | temp : %d\n",index,temp);
        if(ans<res){
            min=i;
            res=ans;
        }
    }
    free(arr);
    return min;
}