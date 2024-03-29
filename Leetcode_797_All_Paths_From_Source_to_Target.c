

void backtrack(int **graph,int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes,int **res,int *temp,int pos,int row){
    if(graphSize-1==row){
        printf("coming in  | pos : %d\n",pos);
        res[*returnSize]=(int*)malloc(sizeof(int)*pos);

        memcpy(res[*returnSize],temp,sizeof(int)*pos);
        for(int i=0;i<pos;i++){
            printf(" %d ",res[*returnSize][i]);
        }
        printf("\n");
        (*returnColumnSizes)[*returnSize]=pos;

        (*returnSize)++;
        printf("returnSize : %d |  returnColumnSizes : %d | size : %d\n",*returnSize,(*returnColumnSizes)[*returnSize-1],pos);
        return;
    }else{
        for(int col=0;col<graphColSize[row];col++){
            // if(graph[row][col]==-1) continue;
            temp[pos]=graph[row][col];
            backtrack(graph,graphSize,graphColSize,returnSize,returnColumnSizes,res,temp,pos+1,graph[row][col]);
        }
    }
}

int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes){
    *returnSize=0;
    *returnColumnSizes=(int*)calloc(10000,sizeof(int));
    int **res=(int**)calloc(10000,sizeof(int*));
    if(graphSize==0) return NULL;
    int *temp=(int*)calloc(graphSize,sizeof(int));
    temp[0]=0;
    for(int col=0;col<graphColSize[0];col++){
        int pos=0;
        temp[++pos]=graph[0][col];
        backtrack(graph,graphSize,graphColSize,returnSize,returnColumnSizes,res,temp,pos+1,graph[0][col]);
    }
    res=(int**)realloc(res,sizeof(int*)*(*returnSize));
    *returnColumnSizes=(int*)realloc(*returnColumnSizes,sizeof(int)*(*returnSize));
    return res;
}