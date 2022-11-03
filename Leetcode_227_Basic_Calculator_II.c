bool isdigits(char s){
    if(s-'0'>=0 && s-'0'<=9){
        return true;
    }
    return false;
}
bool isspaces(char s){
    if(s==32){
        return true;
    }
    return false;
}
int calculate(char * s){
    int slen=strlen(s);
    int stack[slen];
    int top=-1;
    if(!slen) return 0;
    long currnum=0;
    char operater = '+';
    for(int i=0;i<slen;i++){
        char currchar=s[i];
        if(isdigits(currchar)){
            currnum=currnum*10+currchar-'0';
        }
        if(!isdigits(currchar) && !isspaces(currchar) || i==slen-1){
            if(operater=='-'){
                stack[++top]=-1*currnum;
            }else if(operater=='+'){
                stack[++top]=currnum;
            }else if(operater=='*'){
                stack[top]*=currnum;
            }else if(operater=='/'){
                stack[top]/=currnum;
            }
            operater=currchar;
            currnum=0;
        }
    }
    long  result=0;
    while(top!=-1){
        result+=stack[top--];
    }
    return result;
}