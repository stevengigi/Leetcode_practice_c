

int evalRPN(char ** tokens, int tokensSize){
    int *stack=(int*)calloc(tokensSize,sizeof(int));
    int top=-1;
    int temp;
    int var=1;
    // printf(" %d  ",tokensSize);
    for(int i=0;i<tokensSize;i++){
        int index=0;
        temp=0;
        var=1;
        while(tokens[i][index]!='\0'){
            if(tokens[i][index]=='-' && tokens[i][index+1]!='\0'){
                var=-1;
                index++;
            }
            if(tokens[i][index] - '0' >= 0 && tokens[i][index] - '0' <= 9){
                temp=temp*10+(tokens[i][index]-'0');
                index++;
                continue;
            }else{
                switch(tokens[i][index])
                {
                    case '*' :
                        temp=stack[top]*stack[top-1];
                        top=top-2;
                        index++;
                        break;
                    case '+':
                        temp=stack[top]+stack[top-1];
                        top=top-2;
                        index++;
                        break;
                    case '/':
                        temp=stack[top-1]/stack[top];
                        top=top-2;
                        index++;
                        break;
                    case '-':
                        temp=stack[top-1]-stack[top];
                        top=top-2;
                        index++;
                        break;
                    default:break;
                }
            }

        }
        stack[++top]=temp*var;
    }
    return stack[0];
}