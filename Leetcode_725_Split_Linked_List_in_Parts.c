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
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize){
    int count=0;
    *returnSize=k;
    struct ListNode *curr=head;
    while(curr!=NULL){
        count++;
        curr=curr->next;
    }
    struct ListNode **res=(struct ListNode**)malloc(sizeof(struct ListNode*)*k);
    int count_arr[k];
    for(int i=0;i<k;i++){
      count_arr[i]=count/k;
        res[i]=NULL;
    }
    for(int i=0;i<count%k;i++) count_arr[i]++;
    // for(int i=0;i<k;i++) printf(" %d ",count_arr[i]);
    curr=head;
    struct ListNode *ptr;
    for(int i=0;i<k;i++){
        curr=head;

        if(curr==NULL) break;
        res[i]=curr;
        for(int k=1;k<count_arr[i];k++){
            curr=curr->next;
        }
        ptr=curr->next;
        curr->next=NULL;
        head=ptr;
    }
    return res;
}