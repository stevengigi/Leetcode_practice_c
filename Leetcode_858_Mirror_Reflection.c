#include<stdio.h>

int mirrorReflection(int p, int q){
    // (6,2)=(3,1)=1
    // (4,2)=(2,1)=2
    // (10,4)=(5,2)=0
    //Divide p,q by 2 until at least one odd.
    while((p%2==0) && (q%2==0)){
        p/=2;
        q/=2;
    }
    //both p qnd q can't be even
    if((p%2)==0 && (q%2)!=0){
        return 2;//when p is even and q is odd
    }
    if((p%2)!=0 && (q%2)!=0){
        return 1;// when p is odd and q is odd
    }
    return 0;// when p is odd and q is even
}

int main(){
    printf("%d",mirrorReflection(10,4));
}