
void reorderList(struct ListNode* head){
    struct ListNode *ptr=head;
    struct ListNode *stack[50000];
    int size=0;
    while(ptr!=NULL){
        stack[size++]=ptr;
        ptr=ptr->next;
    }
    int top =size-1;
    int down = 1;
    printf("top : %d | size: %d\n",top,size);
    // printf("val : %d\n",stack[1]->val);
    ptr=head;
    for(int i=0;i<size/2;i++){
        printf(" %d ",ptr->val);
        struct ListNode* ttop=stack[top--];
        ttop->next=ptr->next;
        ptr->next=ttop;
        ptr=ptr->next->next;
        printf(" %d ",ptr->val);
    }
    ptr->next=NULL;
}