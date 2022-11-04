bool isvaild(char s){
    if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u' || s=='A' ||s=='E' || s=='I' || s=='O' || s=='U'){
        return true;
    }
    return false;
}

void swap(char *a,char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}

char * reverseVowels(char * s){
    int start=0;
    int end=strlen(s)-1;

    while(start < end){
        while(start<end && !isvaild(s[start])){
            start++;
        }
        while(start<end && !isvaild(s[end])){
            end--;
        }
        swap(&s[start++],&s[end--]);
    }
    return s;
}