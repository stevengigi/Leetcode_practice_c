/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head){
    struct ListNode *dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next=head;
    struct ListNode *prev=head;
    struct ListNode *curr=head->next;
    while(curr!=NULL){
        if(curr->val >= prev->val){
            prev=curr;
            curr=curr->next;
            continue;
        }
        struct ListNode *temp=dummy;
        while(temp->next->val < curr->val){
            temp=temp->next;
        }
        prev->next=curr->next;
        curr->next=temp;
        temp->next=curr;

        curr=prev->next;

    }
    return dummy->next;
}