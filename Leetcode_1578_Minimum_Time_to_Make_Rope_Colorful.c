int max(int a,int b){
    return (a>b)?a:b;
}

int minCost(char * colors, int* neededTime, int neededTimeSize){
    int totaltime=0;
    int i=0,j=0;
    while(i<neededTimeSize && j < neededTimeSize){

        int currtotal=0;
        int currmax=0;
        while(j<neededTimeSize && colors[i]==colors[j]){
            currtotal+=neededTime[j];
            currmax=max(currmax,neededTime[j]);
            j++;
        }
        totaltime+=currtotal-currmax;
        i=j;
    }
    return totaltime;
}