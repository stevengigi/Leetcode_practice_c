#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * removeKdigits(char * num, int k){
    int len=strlen(num);
    if(k>=len){
        return "0";
    }
    char *stack=(char*)malloc(sizeof(char)*len);
    stack[0]=num[0];
    int index=0;
    for(int i=1;i<len;i++){
        if(stack[index]>num[i]){
            while(index>=0 && stack[index]>num[i] && k!=0  ){
                --index;
                k--;
            }
            stack[++index]=num[i];
        }else if(stack[index]<=num[i] || k==0){
            stack[++index]=num[i];
        }
        // printf("k : %d index : %d stack : %c\n",k,index,stack[index]);
    }
    while(k!=0){
        index--;
        k--;
    }
    stack[++index]='\0';
    int i=0;
    while(stack[i]=='0'){
        i++;
    }
    if(i==index){
        return "0";
    }
    // for(int j=i;j<index;j++){
    //     printf("stack : %c\n",stack[j]);
    // }
    return (stack+i);
}

int main(){
    char c[7]="010200";
    int k=2;
    printf("%s\n",removeKdigits(c,k));
}