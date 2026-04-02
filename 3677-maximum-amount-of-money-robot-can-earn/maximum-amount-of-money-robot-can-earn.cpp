class Solution {
    int n, m;
    // int dp[501][501][3];
private:

    // Recursive 
    int solve(int i, int j, int k, vector<vector<int>>& coins) {

        if(i == n-1 && j == m-1) {

            if(coins[i][j] < 0 && k > 0)
                return 0;
            else
                return coins[i][j];
        }
        
        int ans = INT_MIN;

        // Down Movement
        if(i + 1 < n) {
            
            int down;
            if(coins[i][j] < 0 && k > 0){
                down = max(coins[i][j] + solve(i+1, j, k, coins), 
                            solve(i+1, j, k-1, coins));
                ans = max(ans, down);
            }
            else {
                down = coins[i][j] + solve(i+1, j, k, coins);
                ans = max(ans, down);
            }
        }

        // Right Movement
        if(j + 1 < m) {
            
            int right;
            if(coins[i][j] < 0 && k > 0){
                right = max(coins[i][j] + solve(i, j+1, k, coins), 
                            solve(i, j+1, k-1, coins));
                ans = max(ans, right);
            }
            else {
                right = coins[i][j] + solve(i, j+1, k, coins);
                ans = max(ans, right);
            }
        }

        return ans;
    }


    // Recursive + Memoization
    int solveMem(int i, int j, int k, vector<vector<int>>& coins, vector<vector<vector<int>>> &dp) {

        if(i == n-1 && j == m-1) {

            if(coins[i][j] < 0 && k > 0)
                return 0;
            else
                return coins[i][j];
        }

        if(dp[i][j][k] != INT_MIN)
            return dp[i][j][k];
        
        int ans = INT_MIN;

        // Down Movement
        if(i + 1 < n) {
            
            int down;
            if(coins[i][j] < 0 && k > 0){
                down = max(coins[i][j] + solveMem(i+1, j, k, coins, dp), 
                            solveMem(i+1, j, k-1, coins, dp));
                ans = max(ans, down);
            }
            else {
                down = coins[i][j] + solveMem(i+1, j, k, coins, dp);
                ans = max(ans, down);
            }
        }

        // Right Movement
        if(j + 1 < m) {
            
            int right;
            if(coins[i][j] < 0 && k > 0){
                right = max(coins[i][j] + solveMem(i, j+1, k, coins, dp), 
                            solveMem(i, j+1, k-1, coins, dp));
                ans = max(ans, right);
            }
            else {
                right = coins[i][j] + solveMem(i, j+1, k, coins, dp);
                ans = max(ans, right);
            }
        }

        return dp[i][j][k] = ans;
    }

    // Top down
    int solveTab(vector<vector<int>>& coins) {
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));
        
        for(int k = 0; k <= 2; k++) {
            if(coins[n-1][m-1] < 0 && k > 0)
                dp[n-1][m-1][k] = 0;
            else
                dp[n-1][m-1][k] = coins[n-1][m-1];
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){

                if(i == n-1 && j == m-1)
                    continue;

                for(int k = 0; k <= 2; k++){
  
                    int ans = INT_MIN;

                    // Down Movement
                    if(i + 1 < n) {
                        
                        if(dp[i+1][j][k] != INT_MIN)
                            ans = max(ans, coins[i][j] + dp[i+1][j][k]);

                        if(coins[i][j] < 0 && k > 0 && dp[i+1][j][k-1] != INT_MIN)
                            ans = max(ans, dp[i+1][j][k-1]);
                    }

                    // Right Movement
                    if(j + 1 < m) {
                        
                        if(dp[i][j+1][k] != INT_MIN)
                            ans = max(ans, coins[i][j] + dp[i][j+1][k]);

                        if(coins[i][j] < 0 && k > 0 && dp[i][j+1][k-1] != INT_MIN)
                            ans = max(ans, dp[i][j+1][k-1]);
                    }

                    dp[i][j][k] = ans;
                }
            }
        }

        return dp[0][0][2];
    }


public:
    int maximumAmount(vector<vector<int>>& coins) {
        
        n = coins.size();
        m = coins[0].size();
        
        // Recursive
        /*
        return solve(0, 0, 2, coins);
        */

        // Recursive + Memoization
        /*
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));
        return solveMem(0, 0, 2, coins, dp);
        */

        // Tabulation
        return solveTab(coins);
    }
};