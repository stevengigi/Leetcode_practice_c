

bool canConstruct(char * ransomNote, char * magazine){
    int *htable=(int*)calloc(26,sizeof(int));
    for(int i=0;i<strlen(ransomNote);i++){
        htable[ransomNote[i]-'a']++;
    }
    for(int i=0;i<strlen(magazine);i++){
        htable[magazine[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(htable[i]>0) return false;
    }
    return true;
}