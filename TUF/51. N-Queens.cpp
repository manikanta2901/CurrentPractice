class Solution {
public:
    vector<vector<string>>answer;

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

    void nQueens(vector<string>&board,int row,int size){
        if(row == size){
            answer.push_back(board);
            return;
        }
        for(int j = 0; j < size; j++){
            if(isValidPosition(board,row,j,size)){
                board[row][j] = 'Q';
                nQueens(board,row + 1, size);
                board[row][j] = '.';
            }
        }  
    }
    vector<vector<string>> solveNQueens(int n) {
        // vector<string>board(n);
        // int size = n;
        // for(int i = 0; i < size; i++){
        //     for(int j = 0; j < size; j++){
        //         board[i].push_back('.');
        //     }
        // }
        vector<string>board(n,string(n,'.'));
        nQueens(board,0,n);
        return answer;
    }
};