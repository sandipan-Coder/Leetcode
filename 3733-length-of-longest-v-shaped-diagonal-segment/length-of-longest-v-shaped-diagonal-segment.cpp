class Solution {
    vector<vector<int>> directions = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int dp[501][501][4][2];
    int n, m;

private:

    bool check(int row, int col){
        return (row >= 0 && col >= 0 && row < n && col < m);
    }

    // Recursive function
    int solve(int row, int col, int dIdx, bool canTurn, vector<vector<int>>& grid, int val){

        int newRow = row + directions[dIdx][0];
        int newCol = col + directions[dIdx][1];

        if(!check(newRow, newCol) || grid[newRow][newCol] != val)
            return 0;
        
        int len = 0;

        int keepMoving = 1 + solve(newRow, newCol, dIdx, canTurn, grid, (val == 0) ? 2 : 0);
        
        len = max(len, keepMoving);

        if(canTurn)
            len = max(len, 1 + solve(newRow, newCol, (dIdx + 1) % 4, false, grid, (val == 0) ? 2 : 0));

        return len;
    }

    // Recursive + Memoization function
    int solveMem(int row, int col, int dIdx, bool canTurn, vector<vector<int>>& grid, int val){

        int newRow = row + directions[dIdx][0];
        int newCol = col + directions[dIdx][1];

        if(!check(newRow, newCol) || grid[newRow][newCol] != val)
            return 0;
        
        if(dp[newRow][newCol][dIdx][canTurn] != -1)
            return dp[newRow][newCol][dIdx][canTurn];
        
        int len = 0;

        int keepMoving = 1 + solveMem(newRow, newCol, dIdx, canTurn, grid, (val == 0) ? 2 : 0);
        
        len = max(len, keepMoving);

        if(canTurn)
            len = max(len, 1 + solveMem(newRow, newCol, (dIdx + 1) % 4, false, grid, (val == 0) ? 2 : 0));

        return dp[newRow][newCol][dIdx][canTurn] = len;
    }

public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // This is for direction array loop.
                for(int d = 0; d <= 3; d++){
                    if(grid[i][j] == 1){
                        // ans = max(ans, 1 + solve(i, j, d, true, grid, 2));
                        ans = max(ans, 1 + solveMem(i, j, d, true, grid, 2));
                    }
                }
                
            }
        }

        return ans;
    }
};