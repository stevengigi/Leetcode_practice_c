


typedef struct {
    int *array;
    int size;
    int *min;
} MinStack;


MinStack* minStackCreate() {
    MinStack *s=(MinStack *)malloc(sizeof(MinStack));
    s->size=0;
    s->array=NULL;
    s->min=NULL;
    return s;
}

//最小值一直做比較
// ex : stack:[2] min:[2]
//     push(1)
//     stack:[2 1] min [2 1]
//     push(3)
//     stack:[2 1 3] min [2 1 1]
void minStackPush(MinStack* obj, int val) {
    obj->size++;
    obj->array=(MinStack*)realloc(obj->array,obj->size*sizeof(obj->array));
    obj->min=(MinStack*)realloc(obj->min,obj->size*sizeof(obj->array));
    if(obj->size==1){
        obj->array[obj->size-1]=val;
        obj->min[obj->size-1]=val;
    }else{
        obj->array[obj->size-1]=val;
        obj->min[obj->size-1]=(obj->min[obj->size-2]<val)?obj->min[obj->size-2]:val;
    }
}

void minStackPop(MinStack* obj) {
  obj->size--;
}

int minStackTop(MinStack* obj) {
  return obj->array[obj->size-1];
}

int minStackGetMin(MinStack* obj) {
  return obj->min[obj->size-1];
}

void minStackFree(MinStack* obj) {
    free(obj->array);
    free(obj->min);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/