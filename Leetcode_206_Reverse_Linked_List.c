#include<stdio.h>
#include<stdlib.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };

void insert( struct ListNode **l,int n,int data){
    struct ListNode* temp=(struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val=data;
    temp->next=NULL;
    if(n==1){
        temp->next=*l;
        *l=temp;
        return ;
    }
    struct ListNode* temp2=*l;

    for(int i=1;i<n-1;i++){
        temp2=temp2->next;
    }
    temp->next=temp2->next;
    temp2->next=temp;
}

struct ListNode* reverseList(struct ListNode **head){
    if(*head==NULL){
        return *head;
    }
    struct ListNode *current=*head;
    struct ListNode *prev=NULL;
    struct ListNode *next;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
void display(struct ListNode **head){
    struct ListNode *temp=*head;
    while((temp)!=NULL){
        printf(" %d ",temp->val);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
     struct ListNode *head=NULL;
     insert(&head,1,10);
     insert(&head,2,30);
     insert(&head,3,40);
     insert(&head,4,50);
     display(&head);
     head=reverseList(&head);
     display(&head);
}