/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void insertnode(struct ListNode **head,int val){
    struct ListNode *temp=(struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val=val;
    temp->next=NULL;
    if(*head==NULL){
        *head=temp;
    }else{
        struct ListNode *head2=*head;
        while(head2->next!=NULL){
            head2=head2->next;
        }
        head2->next=temp;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(l2==NULL){
        return l1;
    }
    if(l1==NULL){
        return l2;
    }
    int carry=0;
    int digit;
    int val1;
    int val2;
    struct ListNode *res=NULL;
    while(l1!=NULL || l2!=NULL){
        val1=((l1==NULL)?0:l1->val);
        val2=((l2==NULL)?0:l2->val);
        if(l1!=NULL)
            l1=(l1->next==NULL)?NULL:l1->next;
        if(l2!=NULL)
            l2=(l2->next==NULL)?NULL:l2->next;
        digit=val1+val2+carry;
        carry=digit/10;
        digit=digit%10;
        insertnode(&res,digit);
    }
    if(carry){
        insertnode(&res,carry);
    }
    return res;
}