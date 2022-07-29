#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isIsomorphic(char * s, char * t){
    int m1[256] = {0}, m2[256] = {0}, n = strlen(s);
    for (int i = 0; i < n; ++i) {
        if (m1[s[i]] != m2[t[i]]) return false;
        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }
    return true;
}

int main(){
    char s[2]="ab";
    char t[2]="ab";
    printf("ans : %d",isIsomorphic(s,t));
}