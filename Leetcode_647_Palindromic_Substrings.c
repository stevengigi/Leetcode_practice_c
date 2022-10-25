

int countSubstrings(char * s){
    int res=0,left,right;
    int slen=strlen(s);
    for(int i=0;i<slen;i++){
        left=i;
        right=i;
        //Type 1 "a"  "cac"  "bcacb" with odd
        while(left>=0 && right<slen && s[left]==s[right]){
            res+=1;
            left--;
            right++;
        }
        left=i;
        right=i+1;
        // Type 2 "aa" "baab" "cbaabc" with even
        while(left>=0 && right<slen && s[left]==s[right]){
            res+=1;
            left--;
            right++;
        }
    }
    return res;
}