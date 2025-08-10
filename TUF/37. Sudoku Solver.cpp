class Solution {
public:

    bool isValid(vector<vector<char>>&board,int row, int col,int size,char val){

        for(int index = 0; index < size; index++){
            // Checking in row
            if(board[row][index] == val){
                return false;
            }
            // Checking in column
            if(board[index][col] == val){
                return false;
            }
        }

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                // Checking in subMatrix 3 X 3
                int r = (row / 3) * 3 + (i / 3);
                int c = (col / 3) * 3 + (i % 3);
                if(board[r][c] == val){
                    return false;
                }
            }
        }
        return true;
    }

    bool getAnswer(vector<vector<char>>& board,int row,int col,int size){
        if(row == 9){
            return true;
        }
        int nextRow = row,nextCol = col + 1;
        if(nextCol == 9){
            nextCol = 0;
            nextRow = nextRow + 1;
        }

        if(board[row][col] != '.'){
            return getAnswer(board,nextRow,nextCol,size);
        }

       for(char ch = '1'; ch <= '9'; ch++){
            if(isValid(board,row,col,size,ch)){
                board[row][col] = ch;
                if(getAnswer(board,nextRow,nextCol,size)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
       return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        getAnswer(board,0,0,board.size());
    }
};