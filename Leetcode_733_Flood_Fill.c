

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int **image ,int row,int rowsize,int col,int colsize,int color,int target){
    image[row][col]=color;
    if( row-1>=0 && image[row-1][col]==target ){
        dfs(image,row-1,rowsize,col,colsize,color,target);
    }
    if( row+1<rowsize && image[row+1][col]==target ){
        dfs(image,row+1,rowsize,col,colsize,color,target);
    }
    if( col-1>=0 && image[row][col-1]==target ){
        dfs(image,row,rowsize,col-1,colsize,color,target);
    }
    if( col+1 < colsize && image[row][col+1]==target ){
        dfs(image,row,rowsize,col+1,colsize,color,target);
    }

}


int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes){
    int rowsize=imageSize;
    int colsize=*imageColSize;
    if(image[sr][sc]!=color){
        int temp=image[sr][sc];
        dfs(image,sr,rowsize,sc,colsize,color,temp);
    }
    *returnSize=imageSize;
    *returnColumnSizes=imageColSize;
    return image;
}