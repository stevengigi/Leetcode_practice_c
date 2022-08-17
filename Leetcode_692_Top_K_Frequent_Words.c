#include<Stdio.h>
#include<string.h>
#include<stdlib.h>
struct pair{
    char *str;
    int cnt;
};

int cmpstr(const void *a,const void *b){
    const char *pa=*(char**)a;  //做降階
    const char *pb=*(char**)b;  //做降階
    return strcmp(pa,pb);
}

int cmpobj(const void *a,const void *b){
    const struct pair pa=*(struct pair*)a; //做降階
    const struct pair pb=*(struct pair*)b; //做降階
    return pb.cnt-pa.cnt; //由大排到小
}

char ** topKFrequent(char ** words, int wordsSize, int k, int* returnSize){
    qsort(words,wordsSize,sizeof(char**),cmpstr);
    struct pair *obj=(struct pair*)malloc(sizeof(struct pair)*wordsSize);
    int index=0;
    *returnSize=0;
    for(int i=0;i<wordsSize;i++){
        // printf(" %s\n",words[i]);
        obj[index].str=words[i];
        obj[index].cnt=1;
        for(int j=i+1;j<wordsSize;j++){
            if(strcmp(obj[index].str,words[j])!=0){
                i=j-1; //因為做完 i 會在 +1
                index++;
                break;
            }else{
                (obj[index].cnt)++;
            }
            if(j==wordsSize-1) i=j;
        }
    }
    index++;

    qsort(obj,index,sizeof(struct pair),cmpobj);
    for(int i=0;i<k;i++){
        words[(*returnSize)]=obj[(*returnSize)].str;
        (*returnSize)++;
    }
    free(obj);
    return words;
}

int main(){
    char words[6][10] = {"i","love","leetcode","i","love","coding"};
    int k=2;
    int size=sizeof(words)/sizeof(words[0]);
    printf("%d\n",size);
    char *p[size];
    for(int i=0;i<size;i++){
        p[i] = &words[i][0];
    }
    printf("%d\n",size);
    int returnsize;
    char **a=topKFrequent(&p[0],size,k,&returnsize);
    for(int i=0;i<returnsize;i++){
        printf(" %s \n",a[i]);
    }
    return 0;
}

