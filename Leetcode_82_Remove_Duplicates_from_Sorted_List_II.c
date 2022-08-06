/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//reference : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/solution/

struct ListNode* deleteDuplicates(struct ListNode* head){
    //we use three pointer
    struct ListNode *sentinel=(struct ListNode *)malloc(sizeof(struct ListNode)); //dummy
    sentinel->next=head;
    struct ListNode *prev=sentinel;
    while(head){
        //remove duplicate node
        if(head->next!=NULL && head->val==head->next->val){
            while(head->next!=NULL && head->val==head->next->val){
                head=head->next;
            }
            prev->next=head->next;
        }
        // if not prev move
        else{
            prev=prev->next;
        }
        head=head->next;
    }
    return sentinel->next;
}