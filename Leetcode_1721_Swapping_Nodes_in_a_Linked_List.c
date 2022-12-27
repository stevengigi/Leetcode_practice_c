/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapNodes(struct ListNode* head, int k){
    struct ListNode *p1=NULL;
    struct ListNode *p2=NULL;
    for(struct ListNode *p3=head;p3!=NULL;p3=p3->next){
        p2=p2==NULL?NULL:p2->next;
        if(--k==0){
            p1=p3;
            p2=head;
        }
    }
    int temp=p1->val;
    p1->val=p2->val;
    p2->val=temp;

    return head;
}