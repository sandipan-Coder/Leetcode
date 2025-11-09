class Solution {
    int n, m;
    int dp[71][71][71];
private:

    // Recursive 
    int solve(int row, int col1, int col2, vector<vector<int>>& grid){

        // Base Case
        if(col1 >= m || col1 < 0 || col2 >= m || col2 < 0)
            return -1e8;
        
        if(row == n-1){
            if(col1 == col2)
                return grid[row][col1];
            else
                return (grid[row][col1] + grid[row][col2]);
        }

        int maxi = 0;
        // Explore all paths
        for(int j1 = -1; j1 <= 1; j1++){
            for(int j2 = -1; j2 <= 1; j2++){

                if(col1 == col2)
                    maxi = max(maxi, grid[row][col1] + solve(row+1, col1+j1, col2+j2, grid));
                else
                    maxi = max(maxi, grid[row][col1] + grid[row][col2] + solve(row+1, col1+j1, col2+j2, grid));
            }
        }

        return maxi;
    }

    // Recursive + Memoization
    int solveMem(int row, int col1, int col2, vector<vector<int>>& grid){

        // Base Case
        if(col1 >= m || col1 < 0 || col2 >= m || col2 < 0)
            return -1e8;
        
        if(row == n-1){
            if(col1 == col2)
                return grid[row][col1];
            else
                return (grid[row][col1] + grid[row][col2]);
        }

        if(dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        int maxi = 0;
        // Explore all paths
        for(int j1 = -1; j1 <= 1; j1++){
            for(int j2 = -1; j2 <= 1; j2++){

                if(col1 == col2)
                    maxi = max(maxi, grid[row][col1] + solveMem(row+1, col1+j1, col2+j2, grid));
                else
                    maxi = max(maxi, grid[row][col1] + grid[row][col2] + solveMem(row+1, col1+j1, col2+j2, grid));
            }
        }

        return dp[row][col1][col2] = maxi;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();

        // Recursive Solution
        // return solve(0, 0, m-1, grid);

        // Recursive + Memoization
        memset(dp, -1, sizeof(dp));
        return solveMem(0, 0, m-1, grid);
    }
};