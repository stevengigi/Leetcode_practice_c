#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int maxArea(int *height , int heightsize){
    int max=0;
    int area=0;
    int start=0;
    int end=heightsize-1;
    while(start<end){
        if(height[start]<height[end]){
            area=(end-start)*height[start];
            start++;
            if(area>max){
                max=area;
            }
        }else{
            area=(end-start)*height[end];
            end--;
            if(area>max){
                max=area;
            }
        }
    }
    return max;
}

int main(){
    unsigned int seed=time(NULL);
    srand(seed);
    int heightsize=0;
    while(heightsize<=2){
        heightsize=rand()%10;
    }
    int* height=(int*)malloc(sizeof(int)*heightsize);
    for(int i=0;i<heightsize;i++){
        height[i]=rand()%10;
        printf(" %d ",height[i]);
    }
    printf("\n");
    printf("max : %d",maxArea(height,heightsize));
    return 0;
}