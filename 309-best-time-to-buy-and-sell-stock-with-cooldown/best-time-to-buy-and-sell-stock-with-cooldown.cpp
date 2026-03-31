class Solution {
    int n;
private:
    // Recursive 
    int solve(int idx, bool isBuy, vector<int>& prices) {

        if(idx >= n)
            return 0;
        
        int profit = 0;

        if(isBuy) {
            profit = max((-prices[idx] + solve(idx+1, false, prices)),
                        (0 + solve(idx+1, true, prices)));
        } else {
            profit = max((prices[idx] + solve(idx+2, true, prices)),
                        (0 + solve(idx+1, false, prices)));
        }

        return profit;
    }

    // Recursive + Memoization
    int solveMem(int idx, bool isBuy, vector<int>& prices, vector<vector<int>> &dp) {

        if(idx >= n)
            return 0;

        if(dp[idx][isBuy] != -1)
            return dp[idx][isBuy];
        
        int profit = 0;

        if(isBuy) {
            profit = max((-prices[idx] + solveMem(idx+1, false, prices, dp)),
                        (0 + solveMem(idx+1, true, prices, dp)));
        } else {
            profit = max((prices[idx] + solveMem(idx+2, true, prices, dp)),
                        (0 + solveMem(idx+1, false, prices, dp)));
        }

        return dp[idx][isBuy] = profit;
    }

    // Tabulation
    int solveTab(vector<int>& prices) {

        vector<vector<int>> dp(n+3, vector<int>(2, 0));

        for(int idx = n-1; idx >= 0; idx--) {
            for(int buy = 0; buy <= 1; buy++){

                if(buy) {
                    dp[idx][buy] = max((-prices[idx] + dp[idx+1][0]), (0 + dp[idx+1][1]));
                } else {
                    dp[idx][buy] = max((prices[idx] + dp[idx+2][1]), (0 + dp[idx+1][0]));
                }
            }
        }       

        return dp[0][1];
    }

    // Space Optimization
    int solveSpace(vector<int>& prices) {

        vector<int> prev(2, 0);
        vector<int> pPrev(2, 0);
        vector<int> curr(2, 0);

        for(int idx = n-1; idx >= 0; idx--) {
            for(int buy = 0; buy <= 1; buy++){

                if(buy) {
                    curr[buy] = max((-prices[idx] + prev[0]), (0 + prev[1]));
                } else {
                    curr[buy] = max((prices[idx] + pPrev[1]), (0 + prev[0]));
                }
            }

            pPrev = prev;
            prev = curr;
        }       

        return curr[1];
    }


public:
    int maxProfit(vector<int>& prices) {
        
        n = prices.size();
        
        // Recursive 
        /*
        return solve(0, true, prices);
        */

        // Recursive + Memoization
        /*
        vector<vector<int>> dp(n+3, vector<int>(2, -1));
        return solveMem(0, true, prices, dp);
        */

        // Tabulation
        /*
        return solveTab(prices);
        */

        // Space Optimization
        return solveSpace(prices);
    }
};