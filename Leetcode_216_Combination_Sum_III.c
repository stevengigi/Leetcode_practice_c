void backtrack(int k, int n, int start, int cidx, int* returnSize, int** returnColumnSizes, int** res, int* tmp) {
    if (n == 0 && cidx == k) {
        (*returnColumnSizes)[(*returnSize)] = cidx;
        res[(*returnSize)] = (int*) malloc(cidx * sizeof(int));
        memcpy(res[(*returnSize)], tmp, cidx * sizeof(int));
        (*returnSize)++;
    } else {
        for (int i = start; i < 10; i++) {
            if (n - i < 0) break;
            tmp[cidx] = i;
            backtrack(k, n - i, i + 1, cidx + 1, returnSize, returnColumnSizes, res, tmp);
        }
    }
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
    int size = 15;
    *returnSize = 0;
    int** res = (int**) malloc(size * sizeof(int*));
    int* tmp = (int*) malloc(size * sizeof(int));
    *returnColumnSizes = (int*) calloc(size, sizeof(int));
    backtrack(k, n, 1, 0, returnSize, returnColumnSizes, res, tmp);
    free(tmp);
    return res;
}