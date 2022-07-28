#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool isAnagram(char * s, char * t){
    if(strlen(s)!=strlen(t)){
        return false;
    }
    int htable[26]={0};
    for(int i=0;i<strlen(s);i++){
        htable[s[i]-'a']++;
        htable[t[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(htable[i]!=0){
            return false;
        }
    }
    return true;
}
int main(){
    char s[6]="bacba";
    char t[6]="bbaac";
    printf("ans : %d",isAnagram(s,t));
}