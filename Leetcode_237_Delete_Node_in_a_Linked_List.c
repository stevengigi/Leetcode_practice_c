/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *nextnode = node->next;
    node->val=nextnode->val;
    node->next=nextnode->next;
    nextnode->next=NULL;
    free(nextnode);
    return;
}