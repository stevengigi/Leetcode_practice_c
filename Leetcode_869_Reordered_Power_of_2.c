// 利用數字的每個次方 對應到不同的10^n
// ex 46=> 10^6 +10^4 = 64=>10^4+10^6
long counter(long  N) {
    long res = 0;
    for (; N>0; N /= 10) res += pow(10, N % 10);
    // printf("%d\n",res);
    return res;
}

bool reorderedPowerOf2(int N) {
    long c = counter(N);

    for (int i = 0; i < 32; i++)
        if (counter(UINT32_C(1) << i) == c) return true;
    return false;
}

