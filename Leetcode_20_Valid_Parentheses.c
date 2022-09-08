

bool isValid(char * s){
    int len=strlen(s);
    int top=-1;
    char *stack=(char *)malloc(sizeof(char)*len);
    for(int i=0;i<len;i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            stack[++top]=s[i];
        }else if(s[i]==')'){
            if(top!=-1 && stack[top]=='('){
                top--;
            }else{
                return false;
            }
        }else if(s[i]=='}'){
            if(top!=-1 && stack[top]=='{'){
                top--;
            }else{
                return false;
            }
        }else if(s[i]==']'){
            if(top!=-1 && stack[top]=='['){
                top--;
            }else{
                return false;
            }
        }
    }

    return (top==-1)?true:false;
}