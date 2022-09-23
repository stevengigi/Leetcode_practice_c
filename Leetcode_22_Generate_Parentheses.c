

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void backtrack(char **res,int *index,char *s,int pos,int left,int right,int size){
    if(left==0 && right==0){
        char *copy=(char*)malloc(sizeof(char)*(size+1));
        copy[size]='\0';
        strcpy(copy,s);
        res[*index]=copy;
        (*index)++;
        return;
    }
    if(left==0){ //left='(' quantity
        s[pos]=')';
        backtrack(res,index,s,pos+1,left,right-1,size);
    }
    else if(left==right){
        s[pos]='(';
        backtrack(res,index,s,pos+1,left-1,right,size);
    }
    else{
        s[pos]=')';
        backtrack(res,index,s,pos+1,left,right-1,size);

        s[pos]='(';
        backtrack(res,index,s,pos+1,left-1,right,size);
    }
}

char ** generateParenthesis(int n, int* returnSize){
    *returnSize=0;
    char **res=(char**)malloc(sizeof(char*)*10000);
    int size=2*n;
    char *s=(char*)malloc(sizeof(char)*(size+1));

    s[size]='\0';
    int *index=(int*)calloc(1,sizeof(int));
    backtrack(res,index,s,0,n,n,size);
    res=(int**)realloc(res,(*index)*sizeof(char*));
    *returnSize=(*index);
    free(index);
    return res;
}