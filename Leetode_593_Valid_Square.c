void len(int *p1,int *p2,int *queue,int *top){
    int p=(p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
    push(queue,top,p);
}

void push(int *queue,int *top,int p){
    if(*top==-1){
        queue[++(*top)]=p;
        return;
    }
    for(int i=0;i<=*top;i++){
        if(queue[i]==p){
            return;
        }
    }
    queue[++(*top)]=p;
    return;
}

bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size){
    int d1,d2;
    int queue[6]={0};
    int top=-1;
    len(p1,p2,queue,&top);
    len(p1,p3,queue,&top);
    len(p1,p4,queue,&top);
    len(p2,p3,queue,&top);
    len(p2,p4,queue,&top);
    len(p3,p4,queue,&top);
    if(top>=2 || queue[0]==0 || queue[1]==0){
        return false;
    }
    return true;
}