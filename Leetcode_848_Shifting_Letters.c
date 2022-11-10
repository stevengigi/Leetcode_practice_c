char * shiftingLetters(char * s, int* shifts, int shiftsSize){
    // pre sum

    for(int i=shiftsSize-1;i>=0;i--){
        if(i!=shiftsSize-1){
            shifts[i]+=shifts[i+1];
        }
        shifts[i]%=26;
        if('z'-s[i]+1<=shifts[i]){
            s[i]='a'+shifts[i]-('z'-s[i]+1);
        }else{
            s[i]+=shifts[i];
        }
    }
    return s;
}