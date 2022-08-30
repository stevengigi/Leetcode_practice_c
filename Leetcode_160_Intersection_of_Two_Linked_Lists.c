struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *listA=headA;
    struct ListNode *listB=headB;
    //交叉 對比 總共只要怎m+n次(最多)
    // O(m+n)
    while(listA!=listB){
        listA=(listA==NULL)?headB:listA->next;
        listB=(listB==NULL)?headA:listB->next;
    }
    return listA;
}