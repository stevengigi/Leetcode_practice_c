int integerReplacement(int n){
    int count=0;
    long temp=(long)n;
// ex : 5
// (v) 101 -> 100 -> 10 -> 1
// (x) 101 -> 110 -> 11 -> 10 -> 1
// except : 3(例外)
// (v) 11 -> 10 -> 1
// (x) 11 -> 100 -> 10 -> 1
//
// (temp>>1)&1)==0 判斷 temp+1 temp-1 的 1個數(1越少越好)
// temp+1 > temp-1  --n (ex:5,except:3)
// 反之 ++n
    while(temp!=1){
        printf("n : %d\n",temp);
        if((temp&1)==0){
            temp=temp>>1;
        }else if(temp==3 || (((temp>>1)&1)==0)){
            --temp;
        }else{
            ++temp;
        }
        count++;
    }
    return count;
}