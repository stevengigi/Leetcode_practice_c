

bool arrayStringsAreEqual(char ** word1, int word1Size, char ** word2, int word2Size){
    char *w1=(char*)calloc(100000,sizeof(char));
    char *w2=(char*)calloc(100000,sizeof(char));

    for(int i=0;i<word1Size;i++){
        strcat(w1,word1[i]);
    }
    for(int i=0;i<word2Size;i++){
        strcat(w2,word2[i]);
    }
    return !strcmp(w1,w2);
}