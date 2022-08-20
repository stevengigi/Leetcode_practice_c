#define INF (INT_MAX)>>2

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k){
    int *price=(int*)malloc((n)*sizeof(int));
    int *tempprice=(int*)malloc((n)*sizeof(int));
    for(int i=0;i<n;i++){
        price[i]=INF;
        tempprice[i]=INF;
    }
    price[src]=0;
    for(int i=0;i<k+1;i++){
        // src dst price
        for(int j=0;j<flightsSize;j++){
            if(price[flights[j][0]]==INF){
                continue;
            }
            if(price[flights[j][0]]+flights[j][2] < tempprice[flights[j][1]]){
                tempprice[flights[j][1]]=price[flights[j][0]]+flights[j][2];
            }
        }
        memcpy(price, tempprice, n * sizeof(int));
    }
    return (price[dst]==INF)?-1:price[dst];
}