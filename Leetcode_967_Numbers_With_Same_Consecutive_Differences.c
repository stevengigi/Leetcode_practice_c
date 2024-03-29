

void DFS(int x, int n, int k, int* returnSize, int* nums) {
    if(n == 0) {
		nums[(*returnSize)++] = x;
		return;
	}
    int d = x % 10;
    if(d - k >= 0 && d - k < 10)
        DFS((x * 10 + d - k), n-1, k, returnSize, nums);
    if(k > 0 && d + k >= 0 && d + k < 10) // k > 0 to avoid repeat number
        DFS((x * 10 + d + k), n-1, k, returnSize, nums);

}

int* numsSameConsecDiff(int n, int k, int* returnSize){
    int* nums = calloc(1000000, sizeof(int));
    *returnSize = 0;
    for(int i = 1; i <= 9; i++)
        DFS(i, n - 1, k, returnSize, nums);
    return nums;
}