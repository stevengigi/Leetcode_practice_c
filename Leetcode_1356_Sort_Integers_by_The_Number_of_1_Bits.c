struct pair {
    int val;
    int cnt;
};

int cmp(const void* a, const void* b) {
    const struct pair pa = *(const struct pair*) a;
    const struct pair pb = *(const struct pair*) b;
    return pa.cnt == pb.cnt ? pa.val - pb.val : pa.cnt - pb.cnt;
}

int find(int a) {
    int res = 0;
    while (a) {
        res += a % 2;
        a /= 2;
    }
    return res;
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;
    struct pair* pairs = (struct pair*) malloc(arrSize * sizeof(struct pair));
    for (int i = 0; i < arrSize; i++) {
        pairs[i].val = arr[i];
        pairs[i].cnt = find(arr[i]);
    }
    qsort(pairs, arrSize, sizeof(struct pair), cmp);
    for (int i = 0; i < arrSize; i++) {
        arr[i] = pairs[i].val;
    }
    free(pairs);
    return arr;
}