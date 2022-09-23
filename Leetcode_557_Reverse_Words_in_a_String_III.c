void swap(char *a,char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}
void reverse(char *s,int start,int end){ //[start end]
    while(start < end){
        swap(&s[start++],&s[end--]);
    }
}

char * reverseWords(char * s){
    int len=strlen(s);
    int lastindex=-1;

    for(int index=0;index<=len;index++){
        if(s[index]==' ' || s[index]=='\0'){
            int startindex=lastindex+1;
            int endindex=index-1;
            reverse(s,startindex,endindex);
            lastindex=index;
        }
    }
    return s;
}
