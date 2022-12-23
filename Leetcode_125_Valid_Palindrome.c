bool isPalindrome(char * s){
    int len=strlen(s);
    if(len==1) return true;
    int start=0;
    int end=len-1;
    while(start<end){
        while(!islower(s[start]) && !isupper(s[start]) && !isdigit(s[start]) &&start <end){
            start++;
        }
        while(!islower(s[end]) && !isupper(s[end]) && !isdigit(s[end]) && end >start){
            end--;
        }

        if(isupper(s[start])){
            s[start]+=32;
        }
        if(isupper(s[end])){
            s[end]+=32;
        }
        if(s[end]!=s[start]){
            printf("start : %c | end : %c",s[start],s[end]);
            return false;
        }else{
            start++;
            end--;
        }
    }
    return  true;
}