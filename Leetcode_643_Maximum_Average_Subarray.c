double max(double a,double b){
    return (a>b)?a:b;
}

double findMaxAverage(int* nums, int numsSize, int k){
    if(numsSize==1) return *nums;
    double sum=0;
    double res=INT_MIN;
    for(int i=0;i<numsSize;i++){
        if(i<k){
            sum+=(double)nums[i]/k;
            continue;
        }else{
            if(i==k){
                res=max(res,sum);
            }
            sum+=(double)(nums[i]-nums[i-k])/k;

        }
        res=max(res,sum);
    }
    if(numsSize==k) return sum;
    return res;
}