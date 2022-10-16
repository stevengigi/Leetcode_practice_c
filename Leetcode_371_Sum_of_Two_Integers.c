

int getSum(int a, int b){
    unsigned int carry=a&b;
    unsigned int sum=a^b;
    while(carry){
        unsigned int shift=carry << 1;
        carry=sum&shift;
        sum=sum^shift;
    }
    return sum;
}