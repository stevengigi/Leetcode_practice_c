#define e 1000000007
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}

int max(int a,int b){
    return (a>b)?a:b;
}

int maxArea(int h, int w, int* horizontalCuts, int horizontalCutsSize, int* verticalCuts, int verticalCutsSize){
    qsort(horizontalCuts,horizontalCutsSize,sizeof(int),cmp);
    qsort(verticalCuts,verticalCutsSize,sizeof(int),cmp);

    int *hor=(int*)malloc(sizeof(int)*(horizontalCutsSize+1));
    // [1 2 4]
    hor[0]=horizontalCuts[0];
    // [1]
    for(int i=1;i<horizontalCutsSize;i++){
        hor[i]=horizontalCuts[i]-horizontalCuts[i-1];
        // [1 2]
    }
    hor[horizontalCutsSize]=h-horizontalCuts[horizontalCutsSize-1];

    int *ver=(int*)malloc(sizeof(int)*(verticalCutsSize+1));
    ver[0]=verticalCuts[0];
    for(int i=1;i<verticalCutsSize;i++){
        ver[i]=verticalCuts[i]-verticalCuts[i-1];
        // [1 2]
    }
    ver[verticalCutsSize]=w-verticalCuts[verticalCutsSize-1];

    int hmax=INT_MIN;
    int vmax=INT_MIN;
    for(int i=0;i<=horizontalCutsSize;i++){
        hmax=max(hmax,hor[i]);
    }
    for(int i=0;i<=verticalCutsSize;i++){
        vmax=max(vmax,ver[i]);
    }
    return ((long)(vmax%e)*(hmax%e))%e;
}

