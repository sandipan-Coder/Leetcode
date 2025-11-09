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

    // Tabulation
    int solveTab(vector<vector<int>>& grid){

        // Base Case
        for(int j1 = 0; j1 < m; j1++){
            for(int j2 = 0; j2 < m; j2++){
                
                if(j1 == j2)
                    dp[n-1][j1][j2] = grid[n-1][j1];
                else
                    dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        // Explore all paths
        for(int row = n-2; row >= 0; row--){
            for(int col1 = 0; col1 < m; col1++){
                for(int col2 = 0; col2 < m; col2++){

                    int maxi = -1e8;
                    // Explore all paths
                    for(int j1 = -1; j1 <= 1; j1++){
                        for(int j2 = -1; j2 <= 1; j2++){

                            int value = 0;
                            if(col1 == col2)
                                value = grid[row][col1];
                            else
                                value = grid[row][col1] + grid[row][col2];
                            if(col1+j1 >= 0 && col1+j1 < m && col2+j2 >= 0 && col2+j2 < m)
                                value += dp[row+1][col1+j1][col2+j2];
                            else
                                value += -1e8;
                            
                            maxi = max(maxi, value);
                        }
                    }

                    dp[row][col1][col2] = maxi;
                }
            }
        }

        return dp[0][0][m - 1];
    }

    // Space Optimize
    int solveSpace(vector<vector<int>>& grid){

        vector<vector<int>> front(m, vector<int>(m, 0));
        vector<vector<int>> curr(m, vector<int>(m, 0));

        // Base Case
        for(int j1 = 0; j1 < m; j1++){
            for(int j2 = 0; j2 < m; j2++){
                
                if(j1 == j2)
                    front[j1][j2] = grid[n-1][j1];
                else
                    front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        // Explore all paths
        for(int row = n-2; row >= 0; row--){
            for(int col1 = 0; col1 < m; col1++){
                for(int col2 = 0; col2 < m; col2++){

                    int maxi = -1e8;
                    // Explore all paths
                    for(int j1 = -1; j1 <= 1; j1++){
                        for(int j2 = -1; j2 <= 1; j2++){

                            int value = 0;
                            if(col1 == col2)
                                value = grid[row][col1];
                            else
                                value = grid[row][col1] + grid[row][col2];
                            if(col1+j1 >= 0 && col1+j1 < m && col2+j2 >= 0 && col2+j2 < m)
                                value += front[col1+j1][col2+j2];
                            else
                                value += -1e8;
                            
                            maxi = max(maxi, value);
                        }
                    }

                    curr[col1][col2] = maxi;
                }
            }
            front = curr;
        }

        return front[0][m - 1];
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();

        // Recursive Solution
        // return solve(0, 0, m-1, grid);

        // Recursive + Memoization
        /*
        memset(dp, -1, sizeof(dp));
        return solveMem(0, 0, m-1, grid);
        */

        // Tabulation
        /*
        memset(dp, 0, sizeof(dp));
        return solveTab(grid);
        */

        // Space Optimization
        return solveSpace(grid);
    }
};