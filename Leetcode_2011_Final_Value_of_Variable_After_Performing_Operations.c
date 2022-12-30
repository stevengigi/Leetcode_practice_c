int finalValueAfterOperations(char ** operations, int operationsSize){
    char m1[4]="++X";
    char m2[4]="X++";
    char m3[4]="--X";
    char m4[4]="X--";
    int res=0;
    for(int i=0;i<operationsSize;i++){
        if(!strcmp(m1,operations[i]) || !strcmp(m2,operations[i])){
            ++res;
        }else if(!strcmp(m3,operations[i]) || !strcmp(m4,operations[i])){
            --res;
        }
    }
    return res;
}