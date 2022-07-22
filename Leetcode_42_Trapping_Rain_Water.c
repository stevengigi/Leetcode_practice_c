#include<stdio.h>
#include<stdlib.h>

int min(int a,int b){
    return (a>b)?b:a;
}

int max(int a,int b){
    return (a>b)?a:b;
}
// Dynamic Programming
// Time complexity: O(n)
// Space complexity: O(n)
int trap(int* height, int heightSize){
    if(heightSize==0){
        return 0;
    }
    int maxr[heightSize];
    int maxl[heightSize];
    maxl[0]=height[0];
    maxr[heightSize-1]=height[heightSize-1];
    for(int i=1;i<heightSize;i++){
        maxl[i]=max(maxl[i-1],height[i]);
    }
    for(int i=heightSize-2;i>=0;i--){
        maxr[i]=max(maxr[i+1],height[i]);
    }
    int ans=0;
    for(int i=0;i<heightSize;i++){
        ans+=min(maxr[i],maxl[i])-height[i];
    }
    return ans;
}
// Two pointers
// Time complexity: O(n)
// Space complexity: O(1)
int trap2(int* height, int heightSize){
    int l=0;
    int r=heightSize-1;
    int maxL=height[l];
    int maxR=height[r];
    int sum=0;
    while(l<r){
        if(height[l]>height[r]){
            if(maxR-height[r]<0){
                maxR=height[r];
            }else{
                sum+=maxR-height[r];
            }
            r--;
        }else{
            if(maxL-height[l]<0){
                maxL=height[l];
            }else{
                sum+=maxL-height[l];
            }
            l++;
        }
    }
    return sum;
}
// Stacks
// Time complexity: O(n)
// Space complexity: O(n)
int trap3(int* height, int heightSize){
    if(heightSize==1 || heightSize==2){
        return 0;
    }
    int now=0;
    int top=-1;
    int sum=0;
    int stack[heightSize];
    while(now<heightSize){
        while(top!=-1 && height[now]>height[stack[top]]){
            int stacktop=stack[top];
            top--;
            if(top==-1){
                break;
            }
            int distance=now-stack[top]-1;
            int boundh=min(height[now],height[stack[top]])-height[stacktop];
            sum+=distance*boundh;
        }
        top++;
        stack[top]=now;
        now++;
    }
    return sum;
}
int main(){
    int h[6]={4,2,0,3,2,5};
    printf("%d\n",trap(h,sizeof(h)/sizeof(int)));
    printf("%d\n",trap2(h,sizeof(h)/sizeof(int)));
    printf("%d\n",trap3(h,sizeof(h)/sizeof(int)));
}