/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergesort(struct ListNode *list1,struct ListNode *list2){
    if(list1==NULL){
        return list2;
    }
    if(list2==NULL){
        return list1;
    }
    struct ListNode *ptr=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *curr=ptr;
    while(list1!=NULL && list2!=NULL){
        if(list1->val < list2->val){
            curr->next=list1;
            list1=list1->next;
        }else{
            curr->next=list2;
            list2=list2->next;
        }
        curr=curr->next;
    }
    if(list1!=NULL){
        curr->next=list1;
    }
    if(list2!=NULL){
        curr->next=list2;
    }
    return ptr->next;

}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize==0) return NULL;
    if(listsSize==1) return lists[0];
    struct ListNode *result=mergesort(lists[0],lists[1]);
    for(int i=2;i<listsSize;i++){
        result=mergesort(result,lists[i]);
    }
    return result;
}
