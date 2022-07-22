#include<stdio.h>
#include<stdlib.h>

struct stack{
    int index;
    int height;
};
int max(int a,int b){
    return (a>b)?a:b;
}

int largestRectangleArea(int* heights, int heightsSize){
    if(heightsSize==1){
        return heights[0];
    }
    struct stack s[heightsSize];
    int top=-1;
    int maxarea=0;
    int start;
    for(int i=0;i<heightsSize;i++){
        start=i;
        while(top!=-1 && s[top].height > heights[i]){
            start=s[top].index;
            maxarea=max(maxarea,(i-start)*s[top].height);
            top--;
        }
        top++;
        s[top].index=start;
        s[top].height=heights[i];

    }
    for(int i=0;i<=top;i++){
        maxarea=max(maxarea,(heightsSize-s[i].index)*s[i].height);
    }
    return maxarea;
}

int main(){
    int heights[8]={1,2,1,3,2,2,1,1};
    printf("largestRectangleArea : %d",largestRectangleArea(heights,sizeof(heights)/sizeof(int)));
}