#define hashsize 100001
#define max_fre 100

struct node{
    int val;
    int key;
    int count;
    struct node *prev;
    struct node *next;
};

struct queue{
    struct node *head;
    struct node *tail;
    int size; //queue size
};

typedef struct {
    struct queue **queue;
    struct node **hash;
    int capacity;
    int nodecount; //current node number
    int minfreq;
} LFUCache;

struct node *creatnode(int key,int val){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->key=key;
    temp->val=val;
    temp->count=1;
    return temp;
}

struct queue *creatqueue(){
    struct queue *queue=(struct queue*)malloc(sizeof(struct queue));
    queue->head=creatnode(-1,0); //dummy
    queue->tail=creatnode(-1,0); //dummy
    queue->head->next=queue->tail;
    queue->tail->prev=queue->head;
    queue->size=0;
    return queue;
}

struct queue **creatfreqmap(int maxfreq){
    struct queue **queue=(struct queue**)malloc(sizeof(struct queue*)*maxfreq);
    memset(queue,0,sizeof(struct queue*)*maxfreq);
    return queue;
}

struct node **creathash(int capacity){
    struct node **hash=(struct node**)malloc(sizeof(struct node*)*capacity);
    memset(hash,0,sizeof(struct node*)*capacity);
    return hash;
}

void addnode(LFUCache* cache ,struct node *node){
    struct queue *queue=cache->queue[node->count];
    node->next=queue->head->next;
    node->prev=queue->head;
    queue->head->next->prev=node;
    queue->head->next=node;
    queue->size++;
}

void removenode(LFUCache* cache ,struct node *node){
    struct node *prev=node->prev;
    struct node *next=node->next;
    prev->next=next;
    next->prev=prev;
}

void movetohead(LFUCache* cache ,struct node *node){
    // remove node from current freq map
    removenode(cache,node);
    // move node to head of correct freq map
    addnode(cache,node);
}

struct node *poptail(LFUCache* cache,int freq){
    struct queue *queue=cache->queue[freq];
    if(queue==NULL || queue->size==0){
        return NULL;
    }
    struct node *node=queue->tail->prev;
    removenode(cache,node);
    return node;
}

void updateminfreq(LFUCache* cache,struct node *node){
    if(node->count==1){
        cache->minfreq=1;
        return;
    }
    int currminfreq=cache->minfreq;
    if(!cache->queue[currminfreq] || cache->queue[currminfreq]->size==0){
        cache->minfreq=node->count;
    }
}

LFUCache* lFUCacheCreate(int capacity) {
    LFUCache* cache = (LFUCache*)malloc(sizeof(LFUCache));
    cache->queue=creatfreqmap(max_fre);
    cache->hash=creathash(hashsize);
    cache->capacity=capacity;
    cache->nodecount=0;
    cache->minfreq=max_fre;
    return cache;
}

int lFUCacheGet(LFUCache* obj, int key) {
    if(obj->capacity==0){
      return -1;
    }
    struct node *node=obj->hash[key];
    if(node){
        obj->queue[node->count]->size--;  //update size of freqmap
        node->count++;  // increament freq of node
        if(obj->queue[node->count]==NULL){
            obj->queue[node->count]=creatqueue();
        }
        movetohead(obj,node);
        updateminfreq(obj,node);
        return node->val;
    }
    return -1;

}

void lFUCachePut(LFUCache* obj, int key, int value) {
    if(obj->capacity==0){
        return;
    }
    struct node *node=obj->hash[key];
    if(node){
        obj->queue[node->count]->size--;
        node->val=value;
        node->count++;
        if(obj->queue[node->count]==NULL){
            obj->queue[node->count]=creatqueue();
        }
        movetohead(obj,node); // move node to correct freq
        updateminfreq(obj,node); // update min freq variable
    }

    else{ // new node or evict lfu node if cache reached capacity
        if(obj->nodecount==obj->capacity){ // cache reached capacity
            struct node *temp=NULL;
            int index=obj->minfreq;
            temp=poptail(obj,index);
            if(temp){
                obj->queue[temp->count]->size--; // update size of freq map
                obj->hash[temp->key]=NULL; // remove node from hash map
                obj->nodecount--;
            }
        }
        struct node *newnode=creatnode(key,value);
        if(obj->queue[newnode->count]==NULL){
            obj->queue[newnode->count]=creatqueue();
        }
        addnode(obj,newnode);
        updateminfreq(obj,newnode);
        obj->nodecount++; // update cache node count
        obj->hash[key]=newnode; // add key to hash map
    }
}

void lFUCacheFree(LFUCache* obj) {
    free(obj->queue);
    free(obj->hash);
    free(obj);
}

/**
 * Your LFUCache struct will be instantiated and called as such:
 * LFUCache* obj = lFUCacheCreate(capacity);
 * int param_1 = lFUCacheGet(obj, key);

 * lFUCachePut(obj, key, value);

 * lFUCacheFree(obj);
*/
