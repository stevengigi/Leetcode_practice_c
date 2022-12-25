int countTriplets(int* arr, int arrSize){
    int res=0;
    int *prefix=(int *)calloc((arrSize+1),sizeof(int));
    for(int i=0;i<arrSize;i++){
        prefix[i+1]=arr[i]^prefix[i];
    }
    // 0  arr[0]  arr[1]^arr[0] ....   arr[arrSize-1]^...^arr[0];
    for(int i=0;i<arrSize+1;i++){
        printf(" %d ",prefix[i]);
    }
    // Assume a == b, thus
    // a ^ a = b ^ a, thus
    // 0 = b ^ a, thus
    // arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1] ^ arr[j] ^ arr[j + 1] ^ ... ^ arr[k] = 0
    // prefix[k+1] = prefix[i] (arr[0]^...^arr[i]^....^arr[k]=arr[0]^...^arr[i-1])

    // We only need to find out how many pair (i, k) of prefix value are equal.
    // So we can calculate the prefix array first,
    // then brute force count the pair.

    // Because we once we determine the pair (i,k),
    // j can be any number that i < j <= k,
    // so we need to plus k - i - 1 to the result res.
    printf("\n");
    for(int i=0;i<arrSize+1;i++){
        for(int j=i+1;j<arrSize+1;j++){
            if(prefix[i]==prefix[j]){
                res+=j-i-1;
            }
        }
    }
    return res;
}