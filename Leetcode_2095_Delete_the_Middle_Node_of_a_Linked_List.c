/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteMiddle(struct ListNode* head){
    struct ListNode *dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next=head;
    struct ListNode *prevlast=dummy;
    struct ListNode *prev=head;
    struct ListNode *curr=head;
    while(curr!=NULL && curr->next!=NULL){
        prevlast=prev;
        prev=prev->next;
        curr=curr->next->next;
    }
    prevlast->next=prev->next;
    return dummy->next;
}