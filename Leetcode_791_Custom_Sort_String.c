static char pattern[26] = {0};

//
//sort function by pattern
int cmpfunc(const void* x, const void* y){

    return pattern[*(char*)x - 'a'] - pattern[*(char*)y - 'a'];
}

char * customSortString(char * order, char * s){
    //init pattern to {0}
    for(int i = 0; i < 26; i++){
        pattern[i] = 0;
    }
    //build up pattern
    for(int i = 0; i < strlen(order); i++){
        pattern[order[i] - 'a'] = i+1;
    }

    qsort(s, strlen(s), sizeof(char), cmpfunc);
    return s;
}