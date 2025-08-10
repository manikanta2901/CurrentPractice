class Solution {
public:

    bool isValidPosition(vector<string>&board,int i,int j,int size){
        // check row
        for(int row = 0; row < size; row++){
            if(row != i && board[row][j] == 'Q'){
                return false;
            }
        }

        // check column
        for(int col = 0; col < size; col++){
            if(col != j && board[i][col] == 'Q'){
                return false;
            }
        }

        // check left diagonal
        int row = i,col = j;
        while(col >= 0 && row >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }

        // check right diagonal
        row = i,col = j;
        while(row >= 0 && col < size){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col++;
        }
        return true;
    }

    int nQueens(vector<string>&board,int row,int size){
        if(row == size){
            return 1;
        }
        int count = 0;
        for(int j = 0; j < size; j++){
            if(isValidPosition(board,row,j,size)){
                board[row][j] = 'Q';
                count += nQueens(board,row + 1, size);
                board[row][j] = '.';
            }
        }  
        return count;
    }

    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        return nQueens(board,0,n);
    }
};