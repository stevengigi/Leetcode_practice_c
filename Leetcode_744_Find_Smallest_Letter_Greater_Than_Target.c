#include<stdio.h>
#include<stdlib.h>

char nextGreatestLetter(char* letters, int lettersSize, char target){
    int right=lettersSize-1;
    int left=0;
    int m;
    if(target >= letters[right]){
        return letters[0];
    }
    while(left<right){
        m=(right-left)/2+left;
        if(letters[m]>target){
            right=m;
        }else{
            left=m+1;
        }
    }
    return letters[right];
}

int main(){
    char letters[10]={'a','b','d','e','f','h','i','j','x','y'};
    printf("nextGreatestLetter : %c \n",nextGreatestLetter(letters,sizeof(letters)/sizeof(char),'x'));
}