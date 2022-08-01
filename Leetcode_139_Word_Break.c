#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    int len=strlen(s);
    int *dp=(int*)calloc((len+1),sizeof(int));
    dp[len]=1;

    for(int i=len-1;i>=0;i--){
        for(int j=0;j< wordDictSize;j++){
            if(i+strlen(wordDict[j]) <= len && !(strncmp((s+i),wordDict[j],strlen(wordDict[j])))){
                dp[i]=dp[i+strlen(wordDict[j])];
            }
            if(dp[i]==1){ //如果有就跳出去
                break;
            }
        }
    }
    return dp[0]==1;
}

int main(){
    char word[2][5]={{"leet"},{"code"}};
    char *p[2]={&word[0][0],&word[1][0]};
    char s[9]="leetcode";
    printf("%d",wordBreak(s,p,2));
}