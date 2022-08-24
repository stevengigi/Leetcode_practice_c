void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void reverse(int *nums,int start ,int end){
    while(end>start){
        swap(&nums[start],&nums[end]);
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k){
    if(numsSize==1){
        return;
    }
    k=k%numsSize;
    reverse(nums,0,numsSize-k-1);
    reverse(nums,numsSize-k,numsSize-1);
    reverse(nums,0,numsSize-1);
}