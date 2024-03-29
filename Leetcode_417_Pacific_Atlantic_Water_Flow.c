

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int row,int col,int rowsize,int colsize,int ***visit,int prevheight,int **matrix){
    if(col < 0 || row <0 || col==colsize || row==rowsize || matrix[row][col]<prevheight || (*visit)[row][col]==-1){
        return;
    }
    (*visit)[row][col]=-1;
    dfs(row-1,col,rowsize,colsize,visit,matrix[row][col],matrix);
    dfs(row+1,col,rowsize,colsize,visit,matrix[row][col],matrix);
    dfs(row,col-1,rowsize,colsize,visit,matrix[row][col],matrix);
    dfs(row,col+1,rowsize,colsize,visit,matrix[row][col],matrix);
}
int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes){
    *returnSize=0;
    int **pac=(int**)calloc(heightsSize,sizeof(int*));
    int **alt=(int**)calloc(heightsSize,sizeof(int*));
    int **result=(int**)calloc(heightsSize*heightsColSize[0],sizeof(int*));
    for(int i=0;i<heightsSize;i++){
        pac[i]=(int*)calloc((*heightsColSize),sizeof(int));
        alt[i]=(int*)calloc((*heightsColSize),sizeof(int));

    }
    for(int i=0;i<heightsSize*heightsColSize[0];i++){
        result[i]=(int*)calloc(2,sizeof(int));
    }
    for(int i=0;i<*heightsColSize;i++){
        dfs(0,i,heightsSize,heightsColSize[0],&pac,heights[0][i],heights);
        dfs(heightsSize-1,i,heightsSize,heightsColSize[0],&alt,heights[heightsSize-1][i],heights);
    }
    printf("ok1");
    for(int i=0;i<heightsSize;i++){
        dfs(i,0,heightsSize,heightsColSize[0],&pac,heights[i][0],heights);
        dfs(i,heightsColSize[0]-1,heightsSize,heightsColSize[0],&alt,heights[i][heightsColSize[0]-1],heights);
    }
    printf("\nok2\n");
    for(int i=0;i<heightsSize;i++){
        for(int j=0;j<heightsColSize[0];j++){
            if(pac[i][j]==-1 && alt[i][j]==-1){
                result[*returnSize][0]=i;
                result[*returnSize][1]=j;
                (*returnSize)++;
                printf("[%d %d]\n",i,j);
            }
        }
    }
    printf("%d",*returnSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));

    for(int i=0;i<*returnSize;i++){
        (*returnColumnSizes)[i]=2;
    }
    free(pac);
    free(alt);
    return result;
}