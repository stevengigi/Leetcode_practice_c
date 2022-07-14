#include<stdio.h>
#include<stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
 };
void insert( struct ListNode **l,int data,int n){
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
struct ListNode* mergeTwoLists(struct ListNode **list1, struct ListNode **list2){
    if(*list1==NULL) return *list2;
    if(*list2==NULL) return *list1;
    struct ListNode *temp=NULL;
    struct ListNode *head=NULL;
    if((*list1)->val < (*list2)->val){
        temp=*list1;
        *list1=(*list1)->next;
    }else{
        temp=*list2;
        *list2=(*list2)->next;
    }
    head=temp;
    if(*list2==NULL){
        temp->next=*list1;
    }
    if(*list1==NULL){
        temp->next=*list2;
    }
    while(*list1!=NULL && *list2!=NULL){
        if((*list1)->val < (*list2)->val){
            temp->next=*list1;
            *list1=(*list1)->next;
        }else{
            temp->next=*list2;
            *list2=(*list2)->next;
        }
        temp=temp->next;
        if(*list2==NULL){
            temp->next=*list1;
        }
        if(*list1==NULL){
            temp->next=*list2;
        }
    }
    return head;
}

int main(){
    struct ListNode *list1=NULL;
    struct ListNode *list2=NULL;
    insert(&list1,1,1);
    insert(&list1,2,2);
    insert(&list1,4,3);
    insert(&list2,1,1);
    insert(&list2,3,2);
    insert(&list2,4,3);
    struct ListNode *head=mergeTwoLists(&list1,&list2);
    while(head!=NULL){
        printf(" %d ",head->val);
        head=head->next;
    }
}