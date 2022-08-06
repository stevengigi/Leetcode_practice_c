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
    struct node *node=(struct node*)malloc(sizeof(struct node));
    node->next=NULL;
    node->prev=NULL;
    node->val=val;
    return node;
}

struct queue *creatqueue(){
    struct queue *queue=(struct queue*)malloc(sizeof(struct queue));
    queue->head=creatnode(-1);
    queue->tail=creatnode(-1);
    queue->head->next=queue->tail;
    queue->tail->prev=queue->head;
    queue->size=0;
    return queue;
}

typedef struct {
    struct queue *queue;
    int capacity;
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *obj=(MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->queue=creatqueue();
    obj->capacity=k;
    return obj;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if(obj->queue->size==0){
        return true;
    }
    return false;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if(obj->queue->size==obj->capacity){
        return true;
    }
    return false;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if(myCircularDequeIsFull(obj)){
        return false;
    }
    struct node *node=creatnode(value);
    obj->queue->head->next->prev=node;
    node->next=obj->queue->head->next;
    node->prev=obj->queue->head;
    obj->queue->head->next=node;
    obj->queue->size++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if(myCircularDequeIsFull(obj)){
      return false;
    }
    struct node *node=creatnode(value);
    node->prev=obj->queue->tail->prev;
    obj->queue->tail->prev->next=node;
    node->next=obj->queue->tail;
    obj->queue->tail->prev=node;
    obj->queue->size++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj)){
      return false;
    }
    struct node *node=obj->queue->head->next;
    node->next->prev=obj->queue->head;
    obj->queue->head->next=node->next;
    free(node);
    obj->queue->size--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if(myCircularDequeIsEmpty(obj)){
      return false;
    }
    struct node *node=obj->queue->tail->prev;
    obj->queue->tail->prev=node->prev;
    node->prev->next=obj->queue->tail;
    free(node);
    obj->queue->size--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
  return obj->queue->head->next->val;
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
  return obj->queue->tail->prev->val;
}



void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->queue);
    free(obj);
}

int main(){
    MyCircularDeque *obj=myCircularDequeCreate(5);
    printf("%d\n",myCircularDequeInsertFront(obj,5));
    printf("%d\n",myCircularDequeInsertFront(obj,4));
    printf("%d\n",myCircularDequeInsertFront(obj,3));
    printf("%d\n",myCircularDequeInsertLast(obj,2));
    printf("%d\n",myCircularDequeGetFront(obj));
    printf("%d\n",myCircularDequeDeleteFront(obj));
    printf("%d\n",myCircularDequeGetFront(obj));
    myCircularDequeFree(obj);
}