#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int start;
    int end;
    struct node *next;
};

typedef struct {
    struct node *head;
} MyCalendar;


MyCalendar* myCalendarCreate() {
    MyCalendar *obj=(MyCalendar*)malloc(sizeof(MyCalendar));
    obj->head=NULL;
    return obj;
}

bool myCalendarBook(MyCalendar* obj, int start, int end) {
    if(start < 0 || start > end){
        return false;
    }
    struct node *temp=obj->head;
    bool res=true;
    bool made=false;
    struct node *prev=obj->head;
    while(temp){
        if(temp->start < end && temp->end >start){
            res=false;
            break;      //排除所有不行的形況 對比head
        }
        //新增前面的時間 ex (15 20) add(10 15) => (10 15) -> (15 20)
        if(temp->start >= end){
            struct node *new=(struct node*)malloc(sizeof(struct node));
            new->start=start;
            new->end=end;
            made=true;
            if(temp==prev){ //在head的位置
                new->next=temp;
                obj->head=new;
            }
            //新增在任一節點 ex (10 15) -> (30 40) add(20 25)  => (10 15) -> (20 25) -> (30 40)
            else{
                new->next=temp;
                prev->next=new;
            }
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    // 新增的節點在尾端 ex (10 15)->(20 25) add(30 35) => (10 15)->(20 25)->(30 35)
    if(res==true && made==false){
        struct node *tail=(struct node*)malloc(sizeof(struct node));
        tail->start=start;
        tail->end=end;
        tail->next=NULL;
        if(prev){
            prev->next=tail;
        }
        // 一開始就沒有 為NULL
        else{
            obj->head=tail;
        }
    }
    return res;
}

void myCalendarFree(MyCalendar* obj) {
    struct node *prev;
    struct node *curr=obj->head;
    while(curr){
        prev=curr;
        curr=curr->next;
        free(prev);
    }
    return;
}

int main(){
    MyCalendar *obj=myCalendarCreate();
    printf("book : %d\n",myCalendarBook(obj,10,12));
    printf("book : %d\n",myCalendarBook(obj,11,15));
    printf("book : %d\n",myCalendarBook(obj,15,18));
    printf("book : %d\n",myCalendarBook(obj,20,30));
    myCalendarFree(obj);
}