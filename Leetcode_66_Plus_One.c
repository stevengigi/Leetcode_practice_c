#include<stdio.h>
#include<stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize){
    if(digits[digitsSize-1]!=9){
        digits[digitsSize-1]++;
        *returnSize=digitsSize;
        return digits;
    }
    int *ret=(int*)malloc(sizeof(int)*(digitsSize+1));
    int carry=1;
    int i=digitsSize;

    while(i>0){
        ret[i]=(digits[i-1]+carry)%10;
        carry=(carry+digits[i-1])/10;
        i--;
    }
    if(carry==1){
        ret[0]=1;
        *returnSize=digitsSize+1;
        return ret;
    }else{
        *returnSize=digitsSize;
        return &ret[1];
    }

}

int main(){
    int nums[5]={9,9,9,9,9};
    int returnsize;
    int *p=plusOne(nums,sizeof(nums)/sizeof(int),&returnsize);
    for(int i=0;i<returnsize;i++){
        printf(" %d ",p[i]);
    }
    free(p);
}