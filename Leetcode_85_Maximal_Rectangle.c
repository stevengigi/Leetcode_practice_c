#include<stdio.h>
#include<stdlib.h>

struct stack{
    int index;
    int height;
};
int max(int a,int b){
    return (a>b)?a:b;
}
int min(int a,int b){
    return (a>b)?b:a;
}

int trap(int *height,int heightsize){
    struct stack s[heightsize];
    int top=-1;
    int maxarea=0;
    int start;
    for(int i=0;i<heightsize;i++){
        start=i;
        while(top!=-1 && s[top].height > height[i]){
            start=s[top].index;
            maxarea=max(maxarea,s[top].height*(i-start));
            top--;
        }
        top++;
        s[top].index=start;
        s[top].height=height[i];
    }
    for(int i=0;i<=top;i++){
        maxarea=max(maxarea,s[i].height*(heightsize-s[i].index));
    }
    return maxarea;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
//     1  0  1  0  0
//     2  0  2  1  1
//     3  1  3  2  2  =>3*2=6
//     4  0  0  3  0
    int res[*matrixColSize];
    int ans=0;
    for(int i=0;i<*matrixColSize;i++){
        res[i]=matrix[0][i]-'0';
        // printf(" %d ",res[i]);
    }
    ans=max(ans,trap(res,*matrixColSize));
    // printf("\n");
    // printf("ans : %d\n",ans);
    for(int i=1;i<matrixSize;i++){
        for(int j=0;j<*matrixColSize;j++){
            res[j]=(matrix[i][j]=='0')?0:(matrix[i][j]-'0')+res[j];
            // printf(" %d ",res[j]);
        }
        // printf("\n");
        ans=max(ans,trap(res,*matrixColSize));
        // printf("ans : %d\n",ans);
    }
    return ans;
}

int main(){
    char matrix[4][5]={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    char *p[4]={matrix[0],matrix[1],matrix[2],matrix[3]};
    printf("maxtrix  size : %d\n",sizeof(matrix)/sizeof(char));
    int row=sizeof(matrix)/sizeof(matrix[0]);
    printf("maxtrix row size : %d\n",row);
    int col=sizeof(matrix)/(sizeof(matrix)/sizeof(matrix[0]));
    printf("maxtrix column size : %d\n",col);
    printf("maximalRectangle : %d",maximalRectangle(p,row,&col));
}