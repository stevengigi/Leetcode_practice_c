#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int val;
    struct node *next;
    struct node *prev;
};

struct queue{
    struct node *head;
    struct node *tail;
    int size;
};

struct node *creatnode(int val){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->prev=NULL;
    temp->val=val;
    return temp;
}

struct queue *creatqueue(){
    struct queue *queue=(struct queue*)malloc(sizeof(struct queue));
    queue->head=creatnode(-1);
    queue->tail=creatnode(-1);
    queue->size=0;
    queue->head->next=queue->tail;
    queue->tail->prev=queue->head;
    return queue;
}

typedef struct {
    struct queue *queue;
    int capacity;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    if(k==0){
        return NULL;
    }
    MyCircularQueue *obj=(MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->queue=creatqueue();
    obj->capacity=k;
    // printf("%d",obj->queue->head->val);
    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj->queue->size==0){
        return true;
    }
    return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
  if(obj->queue->size==obj->capacity){
      return true;
  }
    return false;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj)){
        printf("\n%d",obj->queue->size);
        return false;
    }
    struct node *node=creatnode(value);
    node->next=obj->queue->head->next;
    obj->queue->head->next->prev=node;
    node->prev=obj->queue->head;
    obj->queue->head->next=node;
    obj->queue->size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
      return false;
    }
    struct node *node=obj->queue->tail->prev;
    obj->queue->tail->prev=node->prev;
    node->prev->next=obj->queue->tail;
    free(node);
    obj->queue->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }
    return obj->queue->tail->prev->val;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }
    return obj->queue->head->next->val;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
    free(obj);
}

int main(){
    MyCircularQueue *obj=myCircularQueueCreate(5);
    printf("%d\n",myCircularQueueEnQueue(obj,1));
    printf("%d\n",myCircularQueueEnQueue(obj,2));
    printf("%d\n",myCircularQueueEnQueue(obj,3));
    printf("%d\n",myCircularQueueRear(obj));
    printf("%d\n",myCircularQueueFront(obj));
}
