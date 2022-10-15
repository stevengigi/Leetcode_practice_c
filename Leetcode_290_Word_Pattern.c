#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

bool wordPattern(char * pattern, char * s){
    int count = 0, plen = strlen(pattern);
    char** translate = calloc(26, sizeof(char*));
    char* token;
    char *del=" ";

    token = strtok(s,del);
    printf("token : %s\n",token);
    while(token && count < plen){

        if (!translate[pattern[count] - 'a']){
            translate[pattern[count] - 'a'] = token;
        }
        else if (strcmp(translate[pattern[count] - 'a'], token)){
            return false;
        }
        token = strtok(NULL, " ");

        count++;
        printf("token : %s | count : %d\n",token,count);
    }

    if(count < plen || token) return false;
     // check if two character have assigned to the same word
    for(int i=0; i < 25; i++)
        if(translate[i])
            for(int j=i+1; j < 26; j++)
                if(translate[j])
                    if(!strcmp(translate[i], translate[j])){
                        free(translate);
                        return false;
                    }
    free(translate);
    return true;
}

void main(){
    char p[5]="abba";
    char s[20]="dog cat cat dog";
    printf("%d",wordPattern(p,s));
}