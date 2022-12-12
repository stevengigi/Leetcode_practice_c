

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findArray(int* pref, int prefSize, int* returnSize){
    *returnSize=prefSize;
    int temp=0;
    for(int i=0;i<prefSize;i++){
        // printf("pref : %d | temp : %d\n",pref[i],temp);
        int index=pref[i];
        pref[i]=temp^pref[i];
        temp=index;
    }
    return pref;
}