class Solution {
private:

    bool isPossible(vector<vector<char>>& board, int row, int col, char num){

        // Row wise check
        for(int i = 0; i < 9; i++){
            if(board[i][col] == num)
                return false;
        }

        // Column wise check
        for(int j = 0; j < 9; j++){
            if(board[row][j] == num)
                return false;
        }

        int r = (row / 3) * 3;
        int c = (col / 3) * 3;

        for(int i = r; i < (r + 3); i++){
            for(int j = c; j < (c + 3); j++){
                if(board[i][j] == num)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int row, int col){

        if(col == 9)
            return solve(board, row + 1, 0);
        if(row == 9)
            return true;

        if(board[row][col] == '.'){
            for(int num = 1; num <= 9; num++){
                if(isPossible(board, row, col, '0' + num)){
                    board[row][col] = '0' + num;
                    bool res = solve(board, row, col + 1);
                    if(res)
                        return true;
                
                    board[row][col] = '.';
                }
            }

            return false;
        }
        else
            return solve(board, row, col + 1);
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};