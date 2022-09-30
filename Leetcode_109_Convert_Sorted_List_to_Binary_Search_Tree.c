/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *toBST(struct ListNode *head,struct ListNode *tail){
    struct ListNode *slow=head;
    struct ListNode *fast=head;
    if(head==tail){
        return NULL;
    }
    while(fast!=tail && fast->next!=tail){
        slow=slow->next;
        fast=fast->next->next;
    }
    struct TreeNode *res=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    res->val=slow->val;
    res->left=toBST(head,slow);
    res->right=toBST(slow->next,tail);
    return res;

}

struct TreeNode* sortedListToBST(struct ListNode* head){
    if(head==NULL){
        return NULL;
    }
    return toBST(head,NULL);
}