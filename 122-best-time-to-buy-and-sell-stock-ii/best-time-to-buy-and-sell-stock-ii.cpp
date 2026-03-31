class Solution {
public:
    // Recursive + Memoization
    int f(int idx,int buy,vector<int>&prices,int n,vector<vector<int>>&dp){

        if(idx == n)
            return 0;
        if(dp[idx][buy] != -1)
            return dp[idx][buy];

        int profit = 0;

        if(buy){
            profit = max(-prices[idx] + f(idx+1,0,prices,n,dp),
                        0 + f(idx+1,1,prices,n,dp));
        }
        else
            profit = max(prices[idx] + f(idx+1,1,prices,n,dp),
                        0 + f(idx+1,0,prices,n,dp));

        return dp[idx][buy] = profit;
    }

    // Tabulation
    int fTab(vector<int>&prices){
        
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2, 0));

        for(int idx = n-1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){

                int profit = 0;
                if(buy){
                    profit = max(-prices[idx] + dp[idx+1][0],
                                0 + dp[idx+1][1]);
                }
                else
                    profit = max(prices[idx] + dp[idx+1][1],
                                0 + dp[idx+1][0]);

                dp[idx][buy] = profit;
            }
        }
        return dp[0][1];
    }

    // Space Optimization
    int fSpace(vector<int>& prices) {

        int n = prices.size(); 
        vector<int> next(2, 0);

        for(int idx = n-1; idx >= 0; idx--){
            vector<int> curr(2, 0);
            for(int buy = 0; buy <= 1; buy++){

                int profit = 0;
                if(buy){
                    profit = max(-prices[idx] + next[0],
                                0 + next[1]);
                }
                else
                    profit = max(prices[idx] + next[1],
                                0 + next[0]);

                curr[buy] = profit;
                next = curr;
            }
        }

        return next[1];
    }

    int maxProfit(vector<int>& prices) {

        // Recursive + Memoization
        /*
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,n,dp);
        */

        // Tabulation
        /*
        return fTab(prices);
        */

        // Space Optimization
        return fSpace(prices);
    }
};