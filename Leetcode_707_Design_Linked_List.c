struct node{
    int val;
    struct node *next;
};

typedef struct {
    struct node *head;
    struct node *tail;
    int size;
} MyLinkedList;


struct node *creatnode(int val){
    struct node *node=(struct node*)malloc(sizeof(struct node));
    node->val=val;
    node->next=NULL;
    return node;
}

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj=(MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head=NULL;
    obj->tail=NULL;
    obj->size=0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index >=obj->size){
        return -1;
    }
    struct node *temp=obj->head;
    for(int i=0;i<index;i++){
        temp=temp->next;
    }
    return temp->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
   struct node *node=creatnode(val);
    node->next=obj->head;
    obj->head=node;
    obj->size++;
    if(obj->size==1){
        obj->tail=obj->head;
    }

}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if(obj->tail!=NULL){
        struct node *node=creatnode(val);
        obj->tail->next=node;
        obj->tail=node;
        obj->size++;
        return;
    }
    else{ //tail is null represent linklist is null for head
        myLinkedListAddAtHead(obj,val);
    }
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index > obj->size){
        return;
    }
    if(index==0){
        return myLinkedListAddAtHead(obj,val);
    }
    if(index==obj->size){
        return myLinkedListAddAtTail(obj,val);
    }
    struct node *node=creatnode(val);
    struct node *temp=obj->head;
    for(int i=0;i<index-1;i++){
        temp=temp->next;
    }
    node->next=temp->next;
    temp->next=node;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index  >= obj->size){
        return;
    }
    struct node *curr;
    struct node *prev=NULL;
    if(index==0){
        curr=obj->head;
        obj->head=curr->next;
        obj->size--;
        free(curr);
        return;
    }
     if(index == obj->size - 1) {
        curr = obj->head;
        while (curr->next != obj->tail)
                curr = curr->next;
        free(curr->next);
        obj->tail = curr;
        obj->size--;
         printf(" %d ",obj->size);
        return;
    }
    curr=obj->head;
    for(int i=0;i<index;i++){
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;
    free(curr);
    obj->size--;
    return;
}

void myLinkedListFree(MyLinkedList* obj) {
    free(obj);
    return;
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/