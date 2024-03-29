struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode* tmpA = head;
    struct ListNode* tmpB = head;
    int sum=0;
    while(tmpA){
        if(tmpA->val==0){
            tmpB->val=sum;
            if(tmpA->next) tmpB=tmpB->next;
            sum=0;
        }else{
            sum+=tmpA->val;
        }
        tmpA=tmpA->next;
    }
    tmpB->next=NULL;
    return head->next;
}