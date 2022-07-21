#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10

struct node{
    int position;
    struct node*next;
};
int hash(int value){
    return (value-48)%size;
}
void insert(struct node ** head,char c,int position){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    int k=hash((int)c);
    temp->position=position;
    temp->next=NULL;
    if(head[k]==NULL){
        head[k]=temp;
    }else{
        struct node *n=head[k];
        temp->next=n;
        head[k]=temp;
    }
}
char findA(struct node **head,char c,int position){
    int k=hash((int)c);
    struct node *current=head[k];
    struct node *prev=head[k];

    while(current!=NULL){
        if(head[k]->position==position){
            head[k]=current->next;
            free(current);
            return 'A';
        }
        if(current->position==position){
            prev->next=current->next;
            free(current);
            return 'A';
        }
        prev=current;
        current=current->next;
    }
    return 'B';
}
char findB(struct node **head,char c){
    int k=hash((int)c);
    if(head[k]!=NULL){
        struct node*temp=head[k];
        head[k]=temp->next;
        free(temp);
        return 'B';
    }else{
        return 'A';
    }
}
char * getHint(char * secret, char * guess){
    struct node *head[size]={NULL};
    int i=0;
    while(secret[i]!='\0'){
        insert(head,secret[i],i);
        i++;
    }
    char s;
    int A=0;
    int B=0;
    int j=0;
    int *index=(int*)calloc((strlen(secret)),sizeof(int));
    i=0;
    while(guess[i]!='\0'){
        s=findA(head,guess[i],i);
        if(s=='A'){
            A++;
        }else{
            index[j]=i;
            j++;
        }
        i++;
    }
    i=0;
    while(i<j){
        printf(" %d ",index[i]);
        s=findB(head,guess[index[i]]);
        if(s=='B'){
            B++;
        }
        i++;
    }
    char* res=(char*)malloc(10*sizeof(char));
    sprintf(res,"%dA%dB",A,B);
    return res;
}
char * getHint2(char * secret, char * guess){
    char *s = malloc(11);
    int bull=0;
    int cow=0;
    int h[10] = {};
    for (int i=0;secret[i] != '\0';i++) {
        h[secret[i]-'0']++;
    }

    // handle bull first!
    for (int i=0;guess[i] != '\0';i++) {
        if (h[guess[i]-'0']) {
            if (guess[i] == secret[i]) {
                bull++;
                h[guess[i]-'0']--;
            }
        }
    }
    for (int i=0;guess[i] != '\0';i++) {
        if (h[guess[i]-'0']) {
            if (guess[i] != secret[i]) {
                cow++;
                h[guess[i]-'0']--;
            }
        }
    }
    sprintf(s, "%dA%dB", bull, cow);
    return s;
}
int main(){
    char secret[5]="1105";
    char guess[5]="1105";
    printf("%s\n",getHint(secret,guess));
    printf("%s\n",getHint2(secret,guess));
}