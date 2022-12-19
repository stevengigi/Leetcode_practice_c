void DFS(char** board, int boardSize, int* boardColSize,int row,int col){
    if(row>=boardSize || col>=*boardColSize || row<0 || col<0 || board[row][col]!='O') return;
    board[row][col]='#';
    DFS(board,boardSize,boardColSize,row-1,col);
    DFS(board,boardSize,boardColSize,row+1,col);
    DFS(board,boardSize,boardColSize,row,col-1);
    DFS(board,boardSize,boardColSize,row,col+1);
}

void solve(char** board, int boardSize, int* boardColSize){
    for(int i=0;i<boardSize;i++){
        if(board[i][0]=='O'){
            DFS(board,boardSize,boardColSize,i,0);
        }
        if(board[i][*boardColSize-1]=='O'){
            DFS(board,boardSize,boardColSize,i,*boardColSize-1);
        }
    }
    for(int i=0;i<*boardColSize;i++){
        if(board[0][i]=='O'){
            DFS(board,boardSize,boardColSize,0,i);
        }
        if(board[boardSize-1][i]=='O'){
            DFS(board,boardSize,boardColSize,boardSize-1,i);
        }
    }
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<*boardColSize;j++){
            if(board[i][j]=='#'){
                board[i][j]='O';
            }else if(board[i][j]=='O'){
                board[i][j]='X';
            }
        }
    }
    return board;
}