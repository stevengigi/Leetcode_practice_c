typedef struct node{
    int val;
    struct node* next;
    struct node* ptr;
}node;


typedef struct {
    struct node* head;
    struct node* tail;
    int n;
} FrontMiddleBackQueue;

FrontMiddleBackQueue* frontMiddleBackQueueCreate() {
    FrontMiddleBackQueue* ret = malloc(sizeof(FrontMiddleBackQueue) );
    ret->head = NULL;
    ret->tail = NULL;
    ret->n = 0;
    return ret;
}

void frontMiddleBackQueuePushFront(FrontMiddleBackQueue* obj, int val) {
    node* item = malloc(sizeof(node));
    item->val = val;
    if(obj->n == 0){
        obj->head = item;
        obj->tail = item;
        item->next = NULL;
        item->ptr = NULL;
    }
    else{
        item->next = obj->head;
        obj->head->ptr = item;
        item->ptr = NULL;
        obj->head = item;
    }
    obj->n += 1;
}

void frontMiddleBackQueuePushMiddle(FrontMiddleBackQueue* obj, int val) {
    int posi = (obj->n) / 2;
    if(posi == 0){
        return frontMiddleBackQueuePushFront(obj, val);
    }
    else{
        node* item = malloc(sizeof(node));
        item->val = val;
        node* tmp = obj->head;
        for(int i = 0; i < posi; i++){
            tmp = tmp->next;
        }
        node* k = tmp->ptr;
        item->next = tmp;
        k->next = item;
        item->ptr = k;
        tmp->ptr = item;
    }
    obj->n += 1;
}

void frontMiddleBackQueuePushBack(FrontMiddleBackQueue* obj, int val) {
    node* item = malloc(sizeof(node));
    item->val = val;
    if(obj->n == 0){
        obj->head = item;
        obj->tail = item;
        item->next = NULL;
        item->ptr = NULL;
    }
    else{
        item->next = NULL;
        item->ptr = obj->tail;
        obj->tail->next = item;
        obj->tail = item;
    }
    obj->n += 1;
}

int frontMiddleBackQueuePopFront(FrontMiddleBackQueue* obj) {
    if(obj->n == 0)
        return -1;

    int ans = obj->head->val;
    node* tmp = obj->head;

    tmp = obj->head;
    obj->n -= 1;
    if(obj->n == 0){
        obj->head = NULL;
        obj->tail = NULL;
    }
    else{
        obj->head = obj->head->next;
        obj->head->ptr = NULL;
    }
    free(tmp);
    return ans;
}
int frontMiddleBackQueuePopBack(FrontMiddleBackQueue* obj) {
    if(obj->n == 0)
        return -1;
    int ans = obj->tail->val;
    node* tmp = obj->tail;
    obj->n -= 1;
    if(obj->n == 0){
        obj->head = NULL;
        obj->tail = NULL;
    }
    else{
        obj->tail = obj->tail->ptr;
        obj->tail->next = NULL;
    }
    free(tmp);
    return ans;
}

int frontMiddleBackQueuePopMiddle(FrontMiddleBackQueue* obj) {
    if(obj->n == 0)
        return -1;
    int ans;
    if(obj->n == 1){
        ans = obj->head->val;
        free(obj->head);
        obj->head = NULL;
        obj->tail = NULL;
    }
    else if(obj->n == 2){
        return frontMiddleBackQueuePopFront(obj);
    }
    else{
        int posi = ((obj->n) - 1) / 2;
        node* tmp = obj->head;
        for(int i = 0; i < posi; i++){
            tmp = tmp->next;
        }
        tmp->ptr->next = tmp->next;
        tmp->next->ptr = tmp->ptr;
        ans = tmp->val;
        free(tmp);
    }
    obj->n -= 1;
    return ans;
}



void frontMiddleBackQueueFree(FrontMiddleBackQueue* obj) {
    node* tmp = obj->head;
    while(tmp){
        obj->head = obj->head->next;
        free(tmp);
        tmp = obj->head;
    }
    free(obj);
}

/**
 * Your FrontMiddleBackQueue struct will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = frontMiddleBackQueueCreate();
 * frontMiddleBackQueuePushFront(obj, val);

 * frontMiddleBackQueuePushMiddle(obj, val);

 * frontMiddleBackQueuePushBack(obj, val);

 * int param_4 = frontMiddleBackQueuePopFront(obj);

 * int param_5 = frontMiddleBackQueuePopMiddle(obj);

 * int param_6 = frontMiddleBackQueuePopBack(obj);

 * frontMiddleBackQueueFree(obj);
*/