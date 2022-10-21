int max(int a,int b){
    return (a>b)?a:b;
}
int min(int a,int b){
    return (a<b)?a:b;
}
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
    int areaA=(ax2-ax1)*(ay2-ay1);
    int areaB=(bx2-bx1)*(by2-by1);
    printf("areaA : %d | areaB : %d\n",areaA,areaB);
    int x_over=min(bx2,ax2)-max(ax1,bx1);
    int y_over=min(by2,ay2)-max(ay1,by1);
    printf("x_over : %d | y_over : %d\n",x_over,y_over);
    int over_area=0;
    if(x_over>0 && y_over >0){
        over_area=y_over*x_over;
    }

    return areaA+areaB-over_area;
}