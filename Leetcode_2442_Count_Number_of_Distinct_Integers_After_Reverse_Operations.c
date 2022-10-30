

int countDistinctIntegers(int* nums, int numsSize){
    int table[1000001]={0};
    int ans=0;
    for(int i=0;i<numsSize;i++){
        int temp=0;
        if(table[nums[i]]==0){
            ans++;
            table[nums[i]]++;
        }
        while(nums[i]!=0){
            temp=temp*10+nums[i]%10;
            nums[i]/=10;
        }
        printf("temp : %d\n",temp);
        if(table[temp]==0){
            ans++;
            table[temp]++;
        }
    }
    return ans;
}