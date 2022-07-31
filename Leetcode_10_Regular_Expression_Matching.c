#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
//reference:https://www.youtube.com/watch?v=HAA8mgxlov8
bool dfs(int i,int lens,char *s,int j,int lenp,char *p){
    if (i>=lens && j>=lenp){
        return true;
    }
    if(j>=lenp){
        return false;
    }
    int match =(i<lens) && ((s[i]==p[j]) || (p[j]=='.'));
    if(j+1<lenp && p[j+1]=='*'){
        return (dfs(i,lens,s,j+2,lenp,p) || (match && dfs(i+1,lens,s,j,lenp,p)));
    }
    if(match){
        return dfs(i+1,lens,s,j+1,lenp,p);
    }
    return false;
}

bool isMatch(char * s, char * p){
    int lens=strlen(s);
    int lenp=strlen(p);
    return dfs(0,lens,s,0,lenp,p);
}

int main(){
    // '.'匹配任意單個字符​​​
    // '*'匹配零個或多個前面的元素
    char s[5]="aabb";
    char p[5]="a*b*";
    printf("ans : %d",isMatch(s,p));
}