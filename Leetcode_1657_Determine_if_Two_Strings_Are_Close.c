int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}

bool closeStrings(char * word1, char * word2){
    int arr1[26]={0};
    int arr2[26]={0};
    int len1=strlen(word1);
    int len2=strlen(word2);
    if(len1!=len2) return 0;
    for(int i=0;i<len1;i++){
        arr1[word1[i]-'a']++;
        arr2[word2[i]-'a']++;
    }

    for(int i = 0; i < 26; i++){
        if(arr1[i]== 0 && arr2[i]!= 0)
            return false;
        if(arr2[i]== 0 && arr1[i]!= 0)
            return false;
    }
    qsort(arr1,26,sizeof(int),cmp);
    qsort(arr2,26,sizeof(int),cmp);
    for(int i=0;i<26;i++){
        if(arr1[i]!=arr2[i]) return false;
    }
    return true;
}