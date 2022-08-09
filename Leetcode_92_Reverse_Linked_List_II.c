/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if(head->next==NULL || head==NULL){
        return head;
    }
    struct ListNode *dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next=head;

    struct ListNode *curr=head;
    struct ListNode *prevlf=dummy;
    //find left pointer
    for(int i=0;i<left-1;i++){
        curr=curr->next;
        prevlf=prevlf->next;
    }
    struct ListNode *prev=NULL;
    struct ListNode *temp;
    //reverse the lnklist
    for(int i=0;i<right-left+1;i++){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    prevlf->next->next=curr;
    prevlf->next=prev;
    return dummy->next;
}