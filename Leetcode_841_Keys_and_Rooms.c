void dfs(int** rooms, int roomsSize, int* roomsColSize,bool *record,int pos){
    record[pos]=true;
    for(int i=0;i<roomsColSize[pos];i++){
        if(record[rooms[pos][i]]==false){
            dfs(rooms,roomsSize,roomsColSize,record,rooms[pos][i]);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){
    bool *record=(bool*)calloc(roomsSize,sizeof(bool));
    dfs(rooms,roomsSize,roomsColSize,record,0);
    for(int i=0;i<roomsSize;i++){
        if(record[i]==false){
            return false;
        }
    }
    return true;
}