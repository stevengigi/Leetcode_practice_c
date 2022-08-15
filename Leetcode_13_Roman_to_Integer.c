#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int romanToInt(char * s){
    int len=strlen(s);
    int sum=0;
    len--;
    int i=0;
    while(i<=len){
        printf("sum:%d\n",sum);
        if(s[i]=='M'){
            sum+=1000;
            i++;
            continue;
        }else if(s[i]=='D'){
            sum+=500;
            i++;
            continue;
        }else if(s[i]=='C'){
            if (i==len){
                sum+=100;
                break;
            }
            if(s[i+1]=='M'){
                sum+=900;
                i+=2;
            }else if(s[i+1]=='D'){
                sum+=400;
                i+=2;
            }else{
                sum+=100;
                i++;
            }
        }else if(s[i]=='L'){
            sum+=50;
            i++;
            continue;
        }else if(s[i]=='X'){
            if (i==len){
                sum+=10;
                break;
            }
            if(s[i+1]=='C'){
                sum+=90;
                i+=2;
            }else if(s[i+1]=='L'){
                sum+=40;
                i+=2;
            }else{
                sum+=10;
                i++;
            }
        }else if(s[i]=='V'){
            sum+=5;
            i++;
            continue;
        }else if(s[i]=='I'){
            if (i==len){
                sum+=1;
                break;
            }
            if(s[i+1]=='X'){
                sum+=9;
                i+=2;
            }else if(s[i+1]=='V'){
                sum+=4;
                i+=2;
            }else{
                sum+=1;
                i++;
            }
        }
    }
    return sum;
}

int main(){
    char s[5]="MMMM";
    printf("%d",romanToInt(s));
}