/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *endoffirsthalf(struct ListNode *root){
    struct ListNode *fast=root;
    struct ListNode *slow=root;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

struct ListNode *revers(struct ListNode *root){
    struct ListNode *prev=NULL;
    struct ListNode *curr=root;
    while(curr!=NULL){
        struct ListNode *temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head){
    if(head==NULL){
        return true;
    }
    struct ListNode *fisrthalfend=endoffirsthalf(head);
    struct ListNode *secondstart=revers(fisrthalfend->next);

    struct ListNode *p1=head;
    struct ListNode *p2=secondstart;
    bool result=true;
    while(result && p2!=NULL){
        if(p1->val!=p2->val) result=false;
        p1=p1->next;
        p2=p2->next;
    }
    fisrthalfend->next=revers(secondstart);
    return result;

}