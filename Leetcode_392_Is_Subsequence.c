#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool isSubsequence(char * s, char * t){
    int s1=0;
    int i=0;
    while(t[i]!='\0'){
        if(s[s1]==t[i]){
            s1++;
        }
        i++;
    }
    if(s[s1]=='\0'){
        return true;
    }else{
        return false;
    }
}


int main(){
    char s[]="ace";
    char t[]="abcdef";
    printf("%d\n",isSubsequence(s,t));
}