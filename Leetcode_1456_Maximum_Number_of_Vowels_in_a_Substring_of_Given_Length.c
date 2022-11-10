int max(int a,int b){
    return a>b?a:b;
}
int maxVowels(char * s, int k){
    int vowels[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1};
    int max_res=0;
    for(int i=0,curr=0;i<strlen(s);i++){
        curr+=vowels[s[i]-'a'];
        if(i>=k){
            curr-=vowels[s[i-k]-'a'];
        }
        max_res=max(curr,max_res);
    }
    return max_res;
}