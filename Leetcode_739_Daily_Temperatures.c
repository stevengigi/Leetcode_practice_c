#include<stdio.h>
#include<stdlib.h>
struct stack{
    int val;
    int index;
};
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize){
    *returnSize=temperaturesSize;
    struct stack stack[temperaturesSize];
    int *res=(int*)calloc(temperaturesSize,sizeof(int));
    stack[0].val=temperatures[0];
    stack[0].index=0;
    int top=0;
    for(int i=1;i<temperaturesSize;i++){
        if(temperatures[i] > stack[top].val){
            while( top!=-1 && temperatures[i] > stack[top].val){
                res[stack[top].index]=i-stack[top].index;
                --top;
            }
        }
        ++top;
        stack[top].val=temperatures[i];
        stack[top].index=i;
    }
    return res;
}
int main(){
    int t[10]={73,74,75,71,69,72,76,73,75,78};
    int returnsize=0;
    int *p=dailyTemperatures(t,sizeof(t)/sizeof(int),&returnsize);
    for(int i=0;i<returnsize;i++){
        printf(" %d ",p[i]);
    }
}