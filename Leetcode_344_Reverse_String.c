#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void reverseString(char* s, int sSize){
    int i=0;
    while(i<sSize/2){
        char temp=s[i];
        s[i]=s[sSize-i-1];
        s[sSize-i-1]=temp;
        i++;
    }
}

int main(){
    char c[10]="abcdefg";
    reverseString(c,strlen(c));
    printf("%s\n",c);
}