

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct{
    char *string;
    char *sort;
}combine;

int cmp(const void *a,const void *b){
    return strcmp((char*)a,(char*)b);
}

int cmpfunc(const void *a,const void *b){
    combine **uni1=(combine**)a;
    char *str1 =(*uni1)->sort;
    combine **uni2 =(combine**)b;
    char *str2 =(*uni2)->sort;

    return strcmp(str1,str2);
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    *returnSize=0;
    *returnColumnSizes=(int*)calloc(strsSize,sizeof(int));

    combine **arr=(combine**)malloc(sizeof(combine*)*strsSize);

    for(int i=0;i<strsSize;i++){
        arr[i]=(combine*)malloc(sizeof(combine));
        arr[i]->string=strs[i];
        arr[i]->sort  =(char*)malloc(sizeof(char)*(strlen(strs[i])+1));
        strcpy(arr[i]->sort,arr[i]->string);
        qsort(arr[i]->sort,strlen(arr[i]->sort),sizeof(char),cmp);
    }
    printf("1------------\n");
    qsort(arr,strsSize,sizeof(combine*),cmpfunc);
    printf("2------------\n");


    char ***ans=(char***)calloc(strsSize,sizeof(char**));
    printf("3------------\n");
    char *temp=NULL;
    for(int i=0;i<strsSize;i++){
        printf(" i : %d start \n",i);
        if(temp==NULL || strcmp(arr[i]->sort,temp)){

            (*returnColumnSizes)[*returnSize]=1;

            ans[*returnSize]=(char**)realloc(ans[*returnSize],sizeof(char*)* (*returnColumnSizes)[*returnSize]);
            printf("fisr one coming\n");
            ans[*returnSize][(*returnColumnSizes)[*returnSize]-1]=arr[i]->string;
            (*returnSize)++;
        }
        else{
            (*returnColumnSizes)[*returnSize-1]++;
            ans[*returnSize-1]=(char**)realloc(ans[*returnSize-1],sizeof(char*)* (*returnColumnSizes)[*returnSize-1]);
            ans[*returnSize-1][(*returnColumnSizes)[*returnSize-1]-1]=arr[i]->string;
        }
        printf(" i : %d end \n",i);
        temp=arr[i]->sort;
    }


    return ans;
}