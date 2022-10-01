

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
    int stop[1001]={0};
    for(int i=0;i<tripsSize;i++){
        stop[trips[i][1]]+=trips[i][0];
        stop[trips[i][2]]-=trips[i][0];
    }
    for(int i=0;capacity>=0 && i<1001;i++){
         capacity -= stop[i];
    }
    return capacity >=0;
}