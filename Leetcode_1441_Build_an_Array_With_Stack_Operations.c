char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char** res = NULL;
    int index = 0;
    *returnSize = 0;
    for (int i = 1; i <= n; i++) {
        if (index >= targetSize) break;
        res = (char**) realloc(res, ((*returnSize) + 1) * sizeof(char**));
        res[(*returnSize)++] = "Push";
        if (i != target[index]) {
            res = (char**) realloc(res, ((*returnSize) + 1) * sizeof(char**));
            res[(*returnSize)++] = "Pop";
        }
        if (i == target[index]) index++;
    }
    return res;
}