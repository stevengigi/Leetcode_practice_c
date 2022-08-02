#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define hashsize 10001

struct node{
    int key;
    int data;
    struct node *next;
    struct node *prev;
};

struct queue{
    struct node *head;
    struct node *tail;
    int count;
};

typedef struct {
    int capacity;
    struct queue *queue;
    struct node **hash;
} LRUCache;

struct node *creatnewnode(int key,int data){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->next=NULL;
    temp->key=key;
    temp->data=data;
    return temp;
}

struct queue *creatqueue(int size){
    struct queue *queue=(struct queue *)malloc(size*sizeof(struct queue));
    queue->head=creatnewnode(-1,0);
    queue->tail=creatnewnode(-1,0);
    queue->head->next=queue->tail;
    queue->tail->prev=queue->head;
    queue->count=0;
    return queue;
}

struct node **hashcreat(int size){
    struct node** hash=(struct node**)malloc(size*sizeof(struct node*));
    memset(hash,0,size*sizeof(struct node*));
    return hash;
}

void removenode(struct node *node){
    struct node *prev=node->prev;
    struct node *next=node->next;
    prev->next=next;
    next->prev=prev;
}
//add new node
void addnode(LRUCache* cache,struct node *node){
    node->prev=cache->queue->head;
    node->next=cache->queue->head->next;
    cache->queue->head->next->prev=node;
    cache->queue->head->next=node;
}

void movetohead(LRUCache* cache,struct node* node){
    removenode(node);
    addnode(cache,node);
}

struct node *poptail(LRUCache* cache){
    struct node *node=cache->queue->tail->prev;
    removenode(node);
    return node;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *LRU=(LRUCache*)malloc(capacity*sizeof(LRUCache));
    LRU->hash=hashcreat(hashsize);
    LRU->queue=creatqueue(capacity);
    LRU->capacity=capacity;
    return LRU;
}

int lRUCacheGet(LRUCache* obj, int key) {
  if(obj->hash[key]!=NULL){
      struct node *node=obj->hash[key];
      int data=node->data;
      movetohead(obj,node);
      return data;
  }
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    struct node *node=obj->hash[key];
    if(!node){
        node=creatnewnode(key,value);
        obj->hash[key]=node;
        addnode(obj,node);
        obj->queue->count++;

        if(obj->queue->count > obj->capacity){
            struct node *tail=poptail(obj);
            obj->hash[tail->key]=NULL;
            obj->queue->count--;
        }
    }
    else{
        node->data=value;
        movetohead(obj,node);
    }
}

void lRUCacheFree(LRUCache* obj) {
    free(obj->hash);
    free(obj->queue);
    free(obj);
}

int main(){
    int capacity=10;
    LRUCache *obj=lRUCacheCreate(capacity);
    lRUCachePut(obj,10,5);
    lRUCachePut(obj,9,6);
    lRUCachePut(obj,8,5);
    lRUCachePut(obj,7,2);
    lRUCachePut(obj,6,1);
    lRUCachePut(obj,5,3);
    lRUCachePut(obj,4,3);
    lRUCachePut(obj,2,6);
    lRUCachePut(obj,1,6);
    lRUCachePut(obj,15,14);
    lRUCachePut(obj,20,11);
    lRUCachePut(obj,18,13);
    lRUCachePut(obj,16,13);
    printf(" %d \n",lRUCacheGet(obj,10));
    printf(" %d \n",lRUCacheGet(obj,9));
    printf(" %d \n",lRUCacheGet(obj,8));
    printf(" %d \n",lRUCacheGet(obj,3));
    lRUCacheFree(obj);
}