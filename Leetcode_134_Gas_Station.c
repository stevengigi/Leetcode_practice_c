

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int totalgas=0;
    int totalcost=0;
    for(int i=0;i<gasSize;i++){
        totalgas+=gas[i];
        totalcost+=cost[i];
    }
    if(totalcost > totalgas){
        return -1;
    }
    int start=0;
    int total=0;
    for(int i=0;i<gasSize;i++){
        total+=gas[i]-cost[i];
        if(total < 0){
            total=0;
            start=i+1;
        }
    }
    return start;
}