

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct{
    char *name;
    int height;
}data;

int cmp(const void *a,const void *b){
    // data aa=*(data*)a;
    return (*(data*)b).height-(*(data*)a).height;
}

char ** sortPeople(char ** names, int namesSize, int* heights, int heightsSize, int* returnSize){
    *returnSize=namesSize;
    data *people=(data*)malloc(sizeof(data)*namesSize);
    for(int i=0;i<namesSize;i++){
        people[i].name=(char*)malloc(sizeof(char)*(strlen(names[i])+1));
        people[i].height=heights[i];
        people[i].name=names[i];
    }
    qsort(people,namesSize,sizeof(data),cmp);
    for(int i=0;i<namesSize;i++){
        names[i]=people[i].name;
    }
    return names;
}