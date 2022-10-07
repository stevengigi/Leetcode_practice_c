

int numOfSubarrays(int* arr, int arrSize, int k, int threshold){
    int sum=0;
    int target=k*threshold;
    int count=0;
    for(int i=0;i<arrSize;i++){
        sum+=arr[i];
        if(i-k+1>0) sum-=arr[i-k];
        if(sum >= target && i-k+1>=0) count++;
    }
    return count;
}