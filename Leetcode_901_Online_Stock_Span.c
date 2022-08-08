#include<stdio.h>
#include<stdlib.h>

struct stack{
    int price;
    int span;
};

typedef struct {
    int index;
    struct stack *arr;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    StockSpanner *obj=(StockSpanner*)malloc(sizeof(StockSpanner));
    obj->arr=(struct stack*)calloc(10000,sizeof(struct stack));
    obj->index=-1;
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int span=1;
    while(obj->index!=-1 && obj->arr[obj->index].price <= price){
        span=span+obj->arr[obj->index].span;
        obj->index--;
    }
    ++obj->index;
    obj->arr[obj->index].price=price;
    obj->arr[obj->index].span=span;
    return span;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj->arr);
    free(obj);
}


int main(){
    StockSpanner *obj=stockSpannerCreate();
    printf(" %d \n",stockSpannerNext(obj,100));
    printf(" %d \n",stockSpannerNext(obj,50));
    printf(" %d \n",stockSpannerNext(obj,40));
    printf(" %d \n",stockSpannerNext(obj,220));
    stockSpannerFree(obj);
}