#include<stdio.h>
#include<stdlib.h>

struct pair{
    int cnt;
    int num;
};

int cmp(const void *a,const void *b){
    const struct pair pa=*(struct pair*)a;
    const struct pair pb=*(struct pair*)b;
    return pa.cnt - pb.cnt;
}

int getKth(int lo, int hi, int k){
    struct pair *res=(struct pair*)malloc((hi-lo+1)*sizeof(struct pair));
    for(int i=lo;i<=hi;i++){
        res[i-lo].num=i;
        int cnt=0;
        int number=i;
        while(number !=1){
            cnt++;
            number=(number%2==0)?number/2:3*number+1;
        }
        res[i-lo].cnt=cnt;
    }
    qsort(res,hi-lo+1,sizeof(struct pair),cmp);
    return res[k-1].num;
}

int main(){
    printf(" %d ",getKth(5,7,1));
}