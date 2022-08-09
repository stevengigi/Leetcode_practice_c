#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Method 1 with two pointer + dp
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int numFactoredBinaryTrees(int* arr, int arrSize){
    int result = 0, mod = pow(10, 9) + 7;
    qsort(arr, arrSize, sizeof(int), cmp);
    long dp[arrSize];
    for(int i = 0; i < arrSize; i++)
        dp[i] = 1;
    for(int i = 0; i < arrSize; i++)
    {
		int left = 0, right = i - 1;
		while (left <= right)
        {
			if((long)arr[left] * arr[right] > arr[i])
				right--;
			else if ((long)arr[left] * arr[right] < arr[i])
				left++;
			else
            {
				if (left == right)
					dp[i] += (dp[left] * dp[right]);
				else
					dp[i] += 2 * (dp[left] * dp[right]);
				left++;
				right--;
			}
		}
		result = ((result % mod) + dp[i]) % mod;
	}
    return result;
}


// Method2 dp

int cmp(const void *a ,const void *b)
{
	return *(int *)a - *(int *)b ;		//從小到大排序，把a，b位置反過來就是從大到小
}

int numFactoredBinaryTrees(int* arr, int arrSize){
    int *dp=(int*)calloc(1000000000,sizeof(int));
    qsort(arr,arrSize,sizeof(int),cmp);
    int res=0;
    int mod=pow(10,9)+7;
    for(int i=0;i<arrSize;i++){
        dp[arr[i]]=1;
        for(int j=0;j<i;j++){
            if(arr[i]%arr[j]==0){
               dp[arr[i]]=(dp[arr[i]]+dp[arr[i]/arr[j]]*dp[arr[j]])%mod;
            }
        }
        // printf(" %d ",dp[arr[i]]);
        res+=dp[arr[i]]%mod;
    }
    return res;
}