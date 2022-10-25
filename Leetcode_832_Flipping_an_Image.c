

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** retforurnColumnSizes){
    *returnSize=imageSize;
    *retforurnColumnSizes=(int*)malloc(sizeof(int)*imageSize);
    for(int i=0;i<imageSize;i++){
        for(int j=0;j<(*imageColSize+1)/2;j++){
            int temp = image[i][j] ^ 1;
            image[i][j] = image[i][*imageColSize-j-1]^1;
            image[i][*imageColSize-j-1]=temp;
        }

        (*retforurnColumnSizes)[i]=*imageColSize;
    }
    return image;
}