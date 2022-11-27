int map[21] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0};

int countPrimeSetBits(int left, int right) {
    int cnt = 0;
    for (int i = left; i <= right; i++) {
        if(map[__builtin_popcount(i)]) cnt++;
    }
    return cnt;
}