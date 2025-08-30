class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int i = 0; i < 9; i++) {
            int rowMap[10] = {0}, colMap[10] = {0};
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && rowMap[board[i][j]-'0']++) 
                    return false;
                if (board[j][i] != '.' && colMap[board[j][i]-'0']++) 
                    return false;
            }
        }

        // check each 3x3 box
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                int boxMap[10] = {0};
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[boxRow+i][boxCol+j];
                        if (c != '.' && boxMap[c-'0']++) 
                            return false;
                    }
                }
            }
        }

        return true;
    }
};