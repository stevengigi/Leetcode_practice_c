#include<stdio.h>
#include<stdlib.h>
int firstUniqChar(char * s){
    int seen[26] = { 0 };
    // memset(seen, 0, sizeof(seen));

    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        seen[s[i] - 'a']++;
    }

    for (int i = 0; i < len; i++) {
        if (seen[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}

int main(){
    char s[5]="aabbc";
    printf("%d",firstUniqChar(s));
}