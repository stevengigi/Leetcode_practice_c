int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int min(int a,int b){
    return (a>b)?b:a;
}
int threeSumClosest(int* nums, int numsSize, int target){
    qsort(nums,numsSize,sizeof(int),cmp);
    if(numsSize==3) return nums[0]+nums[1]+nums[2];
    int close=INT_MAX;
    int ans=0;
    for(int i=0;i<numsSize-2;i++){
        int right=numsSize-1;
        int left=i+1;
        while(left < right){
            int sum=nums[left]+nums[right]+nums[i];
            // printf("%d + %d +%d = %d\n",nums[i],nums[left],nums[right],sum);
            // printf("left : %d , right : %d , i :%d\n",left,right,i);
            if(sum<target){
                if(target-sum < close){
                    close =target-sum;
                    ans=sum;
                }
                left++;
            }
            else if(sum > target){
                if(sum-target < close){
                    close =sum-target;
                    ans=sum;
                }
                right--;
            }
            else{
                return sum;
            }

        }

    }
    return ans;
}