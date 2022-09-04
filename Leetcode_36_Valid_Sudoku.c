

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int rowsize=boardSize;
    int colsize=*boardColSize;
    int shift;
    int row[9]={0};
    int col[9]={0};
    int block[3][3][10]={0};
    for (int c = 0; c < colsize; c++)
    {
        for (int r = 0; r < rowsize; r++)
        {
            if(board[r][c] == '.') continue;

            shift = (board[r][c] - '0');
            if(row[r] & 1 << shift) return false;
            row[r] |= 1 << shift;
            if(col[c] & 1 << shift) return false;
            col[c] |= 1 << shift;
            if(block[r/3][c/3][shift] & 1<<shift) return false;
            block[r/3][c/3][shift]  |=1<<shift;
        }
    }

    return true;
}