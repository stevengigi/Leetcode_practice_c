/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char ** findWords(char ** words, int wordsSize, int* returnSize){
    int map[26] = {1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2};
    *returnSize=0;
    // char** res = (char**) malloc(wordsSize * sizeof(char*));
    for(int i=0;i<wordsSize;i++){
        bool ok=true;
        // int len = strlen(words[i]);
        int tmp=isupper(words[i][0])>0?map[words[i][0]-'A']:map[words[i][0]-'a'];
        for(int j=1;j<strlen(words[i]);j++){
            if(isupper(words[i][j])){
                if(map[words[i][j]-'A']!=tmp){
                    ok=false;
                    break;
                }
            }else{
                if(map[words[i][j]-'a']!=tmp){
                    ok=false;
                    break;
                }
            }
        }
        if(ok) words[(*returnSize)++]=words[i];
    }
    return words;
}