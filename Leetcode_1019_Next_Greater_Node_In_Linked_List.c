/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct stack{
    int val;
    int index;
};
int length(struct ListNode *head){
    struct ListNode *temp=head;
    int len=0;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}
int* nextLargerNodes(struct ListNode* head, int* returnSize){
    int len=length(head);
    printf("%d",len);
    *returnSize=len;

    struct stack stack[len];
    stack[0].val=head->val;
    stack[0].index=0;

    int *res=(int *)calloc(len,sizeof(int));
    head=head->next;
    int top=0;
    int i=1;
    while(head!=NULL){
        while(top!=-1 && head->val > stack[top].val){
            res[stack[top].index]=head->val;
            top--;
        }
        top++;
        stack[top].val=head->val;
        stack[top].index=i;
        i++;
        head=head->next;
    }
    return res;
}





