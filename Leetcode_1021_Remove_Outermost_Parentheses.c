#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * removeOuterParentheses(char * s){
    char *res=(char *)malloc(strlen(s)*sizeof(char));
    //printf("%d",strlen(s));
    int i=0;
    int resindex=0;
    int index=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='('){
            index++;
        }else{
            index--;
        }

        if(s[i]=='(' && index==1){
            continue;
        }else if(index==0){
            continue;
        }else{
            res[resindex]=s[i];
            resindex++;
        }
    }
    res[resindex]='\0';
    return res;
}

int main(){
    char s[15]="((()))(())";
    printf("%s",removeOuterParentheses(s));
}