/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getmid(struct ListNode* head){
    struct ListNode *slow=head;
    struct ListNode *fast=head->next;
    struct ListNode *temp;
    while(fast!=NULL && fast->next!=NULL){
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    temp=slow->next;
    slow->next=NULL;
    return temp;
}

struct ListNode *mergesort(struct ListNode *node1,struct ListNode *node2){
    struct ListNode *prev=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *curr=prev;
    while(node1!=NULL && node2!=NULL){
        if(node1->val<node2->val){
            curr->next=node1;
            node1=node1->next;
        }else{
            curr->next=node2;
            node2=node2->next;
        }
        curr=curr->next;
    }
    if(node1!= NULL){
        curr->next=node1;
    }
    if(node2!=NULL){
        curr->next=node2;
    }
    return prev->next;
}

struct ListNode* sortList(struct ListNode* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct ListNode *left=head;
    struct ListNode *right=getmid(head);
    left=sortList(left);
    right=sortList(right);
    return mergesort(left,right);
}