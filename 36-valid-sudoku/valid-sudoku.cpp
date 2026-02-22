class Solution {
private:

    bool validTraversal(int sRow, int eRow, int sCol, int eCol, vector<vector<char>>& board) {

        set <int> st;
        
        for(int i = sRow; i <= eRow; i++) {
            for(int j = sCol; j <= eCol; j++) {
            
                if(board[i][j] == '.')
                    continue;
                
                int num = board[i][j] - '0';
                if(st.count(num))
                    return false;
                
                st.insert(num);
            }
        }

        return true;
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // Validate rows
        for(int i = 0; i < 9; i++) {
            set <int> st;
            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.')
                    continue;

                int num = board[i][j] - '0';
                if(st.count(num))
                    return false;
                
                st.insert(num);
            }
        }


        // Validate columns
        for(int j = 0; j < 9; j++) {
            set <int> st;
            for(int i = 0; i < 9; i++) {

                if(board[i][j] == '.')
                    continue;

                int num = board[i][j] - '0';
                if(st.count(num))
                    return false;
                
                st.insert(num);
            }
        }

        // Validate 3 X 3 sub-grids
        for(int i = 0; i < 9; i += 3) {
            int er = i + 2;
            for(int j = 0; j < 9; j += 3) {

                int ec = j + 2;

                bool res = validTraversal(i, er, j, ec, board);
                if(!res)
                    return false;
            }
        }

        return true;
    }
};