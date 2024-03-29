/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 int max(int a,int b){
     return a>b?a:b;
 }
int pairSum(struct ListNode* head){
    struct ListNode* slow=head;
    struct ListNode* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("slow : %d | fasr : %d \n",slow->val,fast->val);
    struct ListNode* prev=NULL;
    struct ListNode* temp=slow->next;
    slow->next=prev;
    slow=temp;
    while(slow!=NULL){
        slow=temp->next;
        temp->next=prev;
        prev=temp;
        temp=slow;
    }
    printf("prev : %d \n",prev->val);
    temp=head;
    int res=INT_MIN;
    while(temp!=NULL && prev!=NULL){
        res=max(res,temp->val+prev->val);
        temp=temp->next;
        prev=prev->next;
    }
    return res;

}