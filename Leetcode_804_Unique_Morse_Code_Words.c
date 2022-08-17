#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char map[26][5] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
                   "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                   "..-", "...-", ".--", "-..-", "-.--", "--.."};
int cmp(const void* a, const void* b) {
    const char* pa = *(const char**) a;
    const char* pb = *(const char**) b;
    return strcmp(pa, pb);
}
// Compare function return value Description
// < 0 elem1 less than elem2
// 如果返回值<0，則表明str1小於str2
// 0 elem1 equivalent to elem2
// 如果返回值，如果> 0，則表明str2 小於 str1
// > 0 elem1 greater than elem2
// 如果返回值= 0，則表明str1 等於str2

int uniqueMorseRepresentations(char ** words, int wordsSize){
    if(wordsSize==1){
        return 1;
    }
    char **res=(char**)malloc(sizeof(char*)*wordsSize);
    for(int i=0;i<wordsSize;i++){
        int len=strlen(words[i]);
        res[i]=(char*)calloc((len*4+1),sizeof(char));
        for(int j=0;j<len;j++){
            strcat(res[i], map[words[i][j] - 'a']);
        }
    }
    qsort(res, wordsSize, sizeof(char**), cmp);
    int ans=wordsSize;
    printf("%d\n",ans);
    for(int i=1;i<wordsSize;i++){
        if(!strcmp(res[i],res[i-1])){
        ans--;
        printf("%s  |  %s\n",res[i],res[i-1]);
        }
    }
    for(int i=0;i<wordsSize;i++){
        free(res[i]);
    }
    free(res);
    return ans;
}

int main(){
    char words[5][4]={"gin","zen","gig","msg","gig"};
    char *p[5]={&words[0][0],&words[1][0],&words[2][0],&words[3][0],&words[4][0]};
    int size=sizeof(words)/sizeof(words[0]);
    printf("%d\n",size);
    printf("%d",uniqueMorseRepresentations(&p[0],size));
}