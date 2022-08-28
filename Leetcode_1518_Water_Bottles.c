int numWaterBottles(int numBottles, int numExchange){
    int empty=0;
    int full=numBottles;
    int res=numBottles;
    while(true){
        if(full==0){
            break;
        }
        empty=full+empty;
        full=empty/numExchange;
        empty=empty%numExchange;
        res+=full;

    }
    return res;
}