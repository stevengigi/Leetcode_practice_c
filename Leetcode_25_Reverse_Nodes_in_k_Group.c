/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *getkth(struct ListNode **curr,int k){
    struct ListNode *temp=*curr;
    while(temp!=NULL &&  k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *dummy=(struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val=100;
    dummy->next=head;
    struct ListNode *groupprev=dummy;

    while(true){
        struct ListNode *kth=getkth(&groupprev,k);
        if(kth==NULL){
            break;
        }

        struct ListNode *groupnext=kth->next;
        struct ListNode *prev=kth->next;
        struct ListNode *curr=groupprev->next;
        struct ListNode *temp;
        while(curr!=groupnext){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        // printf("%d",groupprev->val);
        temp=groupprev->next; // temp 會在轉向的起點=轉換的終點(連接下一個group)
        groupprev->next=kth; // groupprev 是初始點或 上一個轉換完後group的末點
        groupprev=temp;  // groupprev 在轉換的終點
        printf("%d ",groupprev->val);
    }
    return dummy->next;

}