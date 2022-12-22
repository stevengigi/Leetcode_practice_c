/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



typedef struct {
    int count;
    struct ListNode *head;
} Solution;


Solution* solutionCreate(struct ListNode* head) {
    Solution *obj=(Solution*)malloc(sizeof(Solution));
    obj->head=head;
    obj->count=0;
    while(head!=NULL){
        obj->count++;
        head=head->next;
    }
    return obj;
}

int solutionGetRandom(Solution* obj) {
    int temp=rand()%obj->count+1;
    struct ListNode *head=obj->head;
    for(int i=1;i<temp;i++){
        head=head->next;
    }
    return head->val;
}

void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);

 * solutionFree(obj);
*/