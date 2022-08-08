/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode *left=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *right=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *ltail=left;
    struct ListNode *rtail=right;
    while(head){
        if(head->val < x){
            ltail->next=head;
            ltail=ltail->next;
        }else{
            rtail->next=head;
            rtail=rtail->next;
        }
        head=head->next;
    }
    rtail->next=NULL;
    ltail->next=right->next;
    return left->next;
}