#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//numRows=3
// 0   4    8     12  -> 0  0+4  4+4  +4=2*(numRows-1)
// 1 3 5 7  9  11 13  -> 1  1+2  3+4  7+2  +2=2*(numRows-1)-2*(current_row) +4=2*(numRows-1)
// 2   6   10
char * convert(char * s, int numRows){
    if(numRows==1){
        return s;
    }
    int len=strlen(s);
    int index=-1;
    char *res=(char*)malloc((len+1)*sizeof(char));
    res[len]='\0';
    for(int i=0;i<numRows;i++){
        int increase=2*(numRows-1);
        for(int j=i;j<len;j+=increase){
            res[++index]=s[j];
            if(i>0 && i <numRows-1 && j+increase - 2*i <len ){
                res[++index]=s[j+increase-2*i];
            }
        }
    }
    printf("%s",res);
    return res;
}

int main(){
    char s[100] = "PAYPALISHIRING";
    int numRows = 3;
    char *p=convert
}