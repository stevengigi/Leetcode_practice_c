/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode *slow=NULL;
    struct ListNode *fast=list1;
    int index=0;
    while(index!=a){
        slow=fast;
        fast=fast->next;
        index++;
    }
    slow->next=list2;
    slow=NULL;
    while(list2->next!=NULL){
        list2=list2->next;
    }
    while(index!=b){
        slow=fast;
        fast=fast->next;
        index++;
    }
    list2->next=fast->next;
    return list1;


}