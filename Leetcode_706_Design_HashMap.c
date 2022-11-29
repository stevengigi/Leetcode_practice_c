


typedef struct {
    int size;
    int *arr;
} MyHashMap;


MyHashMap* myHashMapCreate() {
    MyHashMap *obj=(MyHashMap*)malloc(sizeof(MyHashMap)*1000001);
    obj->size=1000001;
    obj->arr=(int*)malloc(obj->size*sizeof(int));
    for(int i=0;i<1000001;i++){
        obj->arr[i]=-1;
    }
    return obj;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    obj->arr[key]=value;
}

int myHashMapGet(MyHashMap* obj, int key) {
    return obj->arr[key];
}

void myHashMapRemove(MyHashMap* obj, int key) {
    obj->arr[key]=-1;
}

void myHashMapFree(MyHashMap* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);

 * int param_2 = myHashMapGet(obj, key);

 * myHashMapRemove(obj, key);

 * myHashMapFree(obj);
*/