int max(int a,int b){
    return a>b?a:b;
}

int lengthOfLongestSubstring(char * s){
    int table[256]={0};
    int len=strlen(s);
    if(!len) return 0;
    int left=0;
    int right=0;
    int ans=-1;
    for(int i=0;i<len;i++){
        right=i+1;
        if(table[s[i]]==0){
            table[s[i]]=i+1;
            // printf("right : %d\n",right);
            ans=max(ans,right-left);
        }else if(table[s[i]]!=0){
            left=max(left,table[s[i]]);
            // printf("left : %d\n",left);
            table[s[i]]=i+1;
            ans=max(ans,right-left);
        }
        // printf("left : %d right : %d\n",left,right);
    }
    return ans;
}