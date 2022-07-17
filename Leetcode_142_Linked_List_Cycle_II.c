struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    struct ListNode *hare=head; //兔子
    struct ListNode *turtle=head; //烏龜
    while(true){
        if(hare==NULL || hare->next==NULL){
            return NULL;
        }
        turtle=turtle->next;
        hare=hare->next->next;
        if(hare==turtle){
            break;
        }
    }

    while(head!=hare){
        head=head->next;
        hare=hare->next;
    }
    return head;
}
