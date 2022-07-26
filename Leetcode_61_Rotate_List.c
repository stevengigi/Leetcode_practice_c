/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k){
    if(k==0 || head==NULL){
        return head;
    }
    int length=1;
    struct ListNode *last=head;
    while(last->next!=NULL){
        last=last->next;
        length++;
    }
    // printf("length : %d\n",length);
    k=k%length;
    if(k==0){
        return head;
    }
    last->next=head;
    int i=0;
    // 1 -> 2 -> 3 -> 4 -> 5 rotate:3 length=5
    //      ^ : length -rotate -1 往前幾個(from head)
    // 1 -> 2->x 3 -> 4 -> 5 -> 1被rotate到頭的部分
    // => 3 -> 4 -> 5 -> 1 -> 2
    //

    struct ListNode *currnode=head;
    while(i<length-k-1){ //從後面算 rotate 的 list 有多少
        currnode=currnode->next;
        i++;
    }

    head=currnode->next;
    currnode->next=NULL;

    return head;
}