typedef struct {
    int size;
    int current;
    int * queue;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue * que = (MyQueue *)malloc(sizeof(MyQueue));
    que->size = 10;
    que->current = -1;
    que->queue = malloc(sizeof(int) * 10);
    return que;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    obj->current++;
    if (obj->current >= obj->size){
        int * new = malloc(sizeof(int) * 2 * obj->size);
        memcpy(new, obj->queue, sizeof(int) * obj->size);
        free(obj->queue);
        obj->queue = new;
        obj->size *= 2;
    }
    obj->queue[obj->current] = x;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int ele = obj->queue[0];
    for(int i = 0; i < obj->current; i++){
        obj->queue[i] = obj->queue[i+1];
    }
    obj->current -= 1;
    return ele;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    return obj->queue[0];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if(obj->current == -1)
        return true;
    else
        return false;
}

void myQueueFree(MyQueue* obj) {
    free(obj->queue);
    free(obj);
}