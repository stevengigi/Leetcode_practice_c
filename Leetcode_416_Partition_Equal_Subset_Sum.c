

bool canPartition(int* nums, int numsSize){
    int sum=0;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
    }
    // if sum is odd return false;
    if(sum%2) return false;
    sum/=2;
    bool dp[numsSize+1][sum+1];
    for(int i=0;i<sum+1;i++){
        dp[0][i]=false;
    }
    for(int i=0;i<numsSize;i++){
        dp[i][0]=true;
    }
    dp[0][0]=true;
    for(int i=1;i<numsSize+1;i++){
        for(int j=1;j<sum+1;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=nums[i-1]){
                dp[i][j]=(dp[i][j] || dp[i-1][j-nums[i-1]]);
            }
        }
    }
    return dp[numsSize][sum];
}