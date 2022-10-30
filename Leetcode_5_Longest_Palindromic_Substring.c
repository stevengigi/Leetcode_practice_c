

char * longestPalindrome(char * s){
    int slen=strlen(s);
    char *res=(char*)calloc((slen+1),sizeof(char));
    int left,right;
    int reslen=0;
    for(int i=0;i<slen;i++){
        // odd
        left=i;
        right=i;
        while(left>=0 && right <slen && s[left]==s[right]){
            if(right-left+1 > reslen){
                strncpy(res,&s[left],right-left+1);
                reslen=right-left+1;
            }
            left--;
            right++;
        }
        left=i;
        right=i+1;
        // #even
        while(left>=0 && right <slen && s[left]==s[right]){
            if(right-left+1 > reslen){
                strncpy(res,&s[left],right-left+1);
                reslen=right-left+1;
            }
            left--;
            right++;
        }
    }
    return res;
}