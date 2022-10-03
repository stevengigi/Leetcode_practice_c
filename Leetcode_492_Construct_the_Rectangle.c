int max(int a,int b){
    return (a>b)?a:b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize){
    int *res=(int*)calloc(2,sizeof(int));
    *returnSize=2;
    res[0]=INT_MAX;
    for(int i=1;i<=area;i++){
        if(area%i==0){
            int l=max(area/i,area/(area/i));
            int w=area/l;
            if(l-w < res[0]-res[1]){
                res[0]=l;
                res[1]=w;
            }
        }
    }
    return res;
}