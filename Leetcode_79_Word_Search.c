bool dfs(char** board,int row,int rowsize,int col,int colsize,char *word ,int index,int len){
    if(index==len){
        return true;
    }

    if(row <0 || row >=rowsize || col<0 || col>=colsize || board[row][col]!=word[index]){
        return false;
    }
    char temp=board[row][col];
    board[row][col]=' ';
    bool res=dfs(board,row+1,rowsize,col,colsize,word,index+1,len) ||
        dfs(board,row-1,rowsize,col,colsize,word,index+1,len) ||
        dfs(board,row,rowsize,col+1,colsize,word,index+1,len) ||
        dfs(board,row,rowsize,col-1,colsize,word,index+1,len);
    board[row][col]=temp;
    return res;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    int rowsize=boardSize,colsize=boardColSize[0],len=strlen(word);
    for(int row=0;row<rowsize;row++){
        for(int col=0;col<colsize;col++){
            if(dfs(board,row,rowsize,col,colsize,word,0,len)) return true;
        }
    }
    return false;
}