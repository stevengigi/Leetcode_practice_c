// - 00  dead (next) <- dead (current)
// - 01  dead (next) <- live (current)  lives < 2
// - 10  live (next) <- dead (current)  lives==3
// - 11  live (next) <- live (current)  3>=lives>=2

int max(int a,int b){
    return (a>b)?a:b;
}
int min(int a,int b){
    return (a>b)?b:a;
}

int lives(int **board,int row,int col,int rowsize,int colsize){
    int live = 0;
    for(int i=max(row-1,0);i<=min(rowsize,row+1);i++){
        for(int j=max(col-1,0);j<=min(colsize,col+1);j++){
            live+=board[i][j] & 1;
        }
    }
    live-=board[row][col]&1;
    printf(" %d ",live);
    return  live;
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    int rowsize=boardSize-1;
    int colsize=*boardColSize-1;
    for(int i=0;i<=rowsize;i++){
        for(int j=0;j<=colsize;j++){
            int live=lives(board,i,j,rowsize,colsize);
            if(live>=2 && live <=3 && (board[i][j]== 1)){
                board[i][j]=3; // 11
            }
            else if(live==3 && (board[i][j]==0)){
                board[i][j]=2;
            }
        }
    }
    for(int i=0;i<=rowsize;i++){
        for(int j=0;j<=colsize;j++){
            board[i][j] >>=1;
        }
    }
    return board;
}

