

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    int top=-1;
    int stack[pushedSize];
    int push=0;
    int pop=0;
    while(push!=pushedSize){
        if(top==-1){
            stack[++top]=pushed[push++];
        }else if(stack[top]==popped[pop]){
            top--;
            pop++;
        }else{
            stack[++top]=pushed[push++];
        }
    }
    while(pop!=poppedSize){
        if(stack[top]!=popped[pop]){
            return false;
        }
        top--;
        pop++;
    }
    return true;
}