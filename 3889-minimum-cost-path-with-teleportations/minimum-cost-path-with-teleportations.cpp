class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();
        const int inf = INT_MAX;

        vector<vector<int>> dp(n, vector<int>(m, inf));
        dp[0][0] = 0;

        // Calculate only the simple moves (right, bottom)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) {

                if(i == 0 && j == 0)
                    continue;
                
                if(i - 1 >= 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
                
                if(j - 1 >= 0)
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }

        // Now consider the teleportation moves.
        for(int tele = 1; tele <= k; tele++)  {

            const int MAX = 1e4;
            vector<int> best(MAX + 1, inf);

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {

                    best[grid[i][j]] = min(best[grid[i][j]], dp[i][j]);
                }
            }

            for(int val = MAX-1; val >= 0; val--)
                best[val] = min(best[val], best[val + 1]);
            
            // It Store in every Teleportation what is the minimum cost
            vector<vector<int>> newDP(n, vector<int>(m, inf));
            newDP[0][0] = 0;

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {

                    if(i == 0 && j == 0)
                        continue;
                    
                    newDP[i][j] = best[grid[i][j]];

                    if(i - 1 >= 0)
                        newDP[i][j] = min(newDP[i][j], newDP[i - 1][j] + grid[i][j]);
                    
                    if(j - 1 >= 0)
                        newDP[i][j] = min(newDP[i][j], newDP[i][j - 1] + grid[i][j]);
                }
            }

            dp = newDP;
        }

        return dp[n - 1][m - 1];
    }
};