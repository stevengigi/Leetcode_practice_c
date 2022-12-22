void swap(int *a,int *b){
    int temp=*b;
    *b=*a;
    *a=temp;
}
void reverse(int *nums,int start,int end){
    while(start<end){
        swap(&nums[start++],&nums[end--]);
    }
}
void nextPermutation(int* nums, int numsSize){
    int k=-1;
    for(int i=numsSize-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            k=i;
            break;
        }
    }
    if(k<0){
        reverse(nums,0,numsSize-1);
        return;
    }else{
        for(int i=numsSize-1;i>=0;i--){
            if(nums[i]>nums[k]){
                swap(&nums[i],&nums[k]);
                break;
            }
        }
        reverse(nums,k+1,numsSize-1);
    }
}