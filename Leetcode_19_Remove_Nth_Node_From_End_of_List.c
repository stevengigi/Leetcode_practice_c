//Method 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int length(struct ListNode *head){
    int i=0;
    struct ListNode *temp=head;
    while(temp!=NULL){
        i++;
        temp=temp->next;
    }
    return i;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    int len=length(head);
    int i=0;
    struct ListNode* curr=head;
    struct ListNode* prev=NULL;
    if(len-n==0){
        curr=curr->next;
        return curr;
    }
    while(i<len-n){
        prev=curr;
        curr=curr->next;
        i++;
    }
    prev->next=curr->next;

    // printf("%d %d",len,head->val);
    return head;
}
//Method 2
/*two pointer*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    struct ListNode* left=head;
    struct ListNode* prev=left;
    struct ListNode* right=head;
    while(n>0 && right!=NULL){
        right=right->next;
        n--;
    }
    if(right==NULL){
        return head->next;
    }
    while(right!=NULL){
        prev=left;
        left=left->next;
        right=right->next;
    }
    prev->next=left->next;
    return head;
}