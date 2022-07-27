
/*Method 1 reverse */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reverse(struct ListNode* temp,struct ListNode** head){
    if(temp->next==NULL){
        *head=temp;
        return;
    }
    reverse(temp->next,head);
    struct ListNode *temp2=temp->next;
    temp2->next=temp;
    temp->next=NULL;
}
int linklistlen(struct ListNode *head){
    if(head==NULL){
        return 0;
    }
    return 1+linklistlen(head->next);
}
void insertnode(struct ListNode **head,int val){
    struct ListNode *temp=(struct ListNode*)malloc(sizeof(struct ListNode));
    temp->next=NULL;
    temp->val=val;
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
    struct ListNode *l1head=l1;
    struct ListNode *l2head=l2;
    int length1;
    int length2;
    length1=linklistlen(l1);
    length2=linklistlen(l2);
    reverse(l1,&l1head);
    reverse(l2,&l2head);
    printf("length1 : %d\n",length1);
    printf("l1head->val : %d\n",l1head->val);
    printf("length2 : %d\n",length2);
    printf("l2head->val : %d\n",l2head->val);
    int digit;
    int carry=0;
    struct ListNode *res=NULL;
    while(l1head!=NULL || l2head!=NULL || carry!=0){
        digit=carry+((l1head==NULL)?0:l1head->val)+((l2head==NULL)?0:l2head->val);
        carry=digit/10;
        digit=digit%10;
        insertnode(&res,digit);
        printf("digit : %d\n",digit);
        if(l1head!=NULL)
            l1head=(l1head->next==NULL)?NULL:l1head->next;
        if(l2head!=NULL)
            l2head=(l2head->next==NULL)?NULL:l2head->next;
    }
    reverse(res,&res);
    return res;
}

/*Method 2 stack */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int linklistlen(struct ListNode *head){
    if(head==NULL){
        return 0;
    }
    return 1+linklistlen(head->next);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int length1;
    int length2;
    length1=linklistlen(l1);
    length2=linklistlen(l2);
    int length3=0;
    int stack1[length1];
    int stack2[length2];
    int stack3[(length2>length1)?length2+1:length1+1];
    for(int i=0;i<length1;i++){
        stack1[i]=l1->val;
        printf("stack : %d\n",stack1[i]);
        l1=l1->next;
    }
    for(int i=0;i<length2;i++){
        stack2[i]=l2->val;
        l2=l2->next;
    }
    int digit;
    int carry=0;
    while(length2!=0 || length1!=0 || carry!=0){
        digit=((length2==0)?0:stack2[--length2])+((length1==0)?0:stack1[--length1])+carry;
        carry=digit/10;
        digit=digit%10;
        stack3[length3]=digit;
        printf("stack3 : %d\n",stack3[length3]);
        length3++;
    }
    struct ListNode *res=(struct ListNode*)malloc(sizeof(struct ListNode));
    res->val=0;
    res->next=NULL;
    struct ListNode* current=res;
    while(length3!=0){
        current->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        current->next->val=stack3[--length3];
        current->next->next=NULL;
        current=current->next;

    }
    return res->next;
}