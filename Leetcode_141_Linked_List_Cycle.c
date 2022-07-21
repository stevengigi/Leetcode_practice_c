/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head==NULL){
        return false;
    }
    struct ListNode *harr=head;
    struct ListNode *turtle=head;
    while(true){
        if(harr==NULL || harr->next==NULL){
            return false;
        }
        harr=harr->next->next;
        turtle=turtle->next;
        if(harr==turtle){
            return true;
        }
    }
}