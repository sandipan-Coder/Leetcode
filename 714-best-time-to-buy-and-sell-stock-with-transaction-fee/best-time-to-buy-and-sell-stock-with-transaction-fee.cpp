class Solution {
    int n;
private:

    int solveMem(int idx, bool isBuy, vector<int>& prices, vector<vector<int>> &dp, int &fee) {

        if(idx >= n)
            return 0;

        if(dp[idx][isBuy] != -1)
            return dp[idx][isBuy];
        
        int profit = 0;

        if(isBuy) {
            profit = max((-prices[idx] + solveMem(idx+1, false, prices, dp, fee)),
                        (0 + solveMem(idx+1, true, prices, dp, fee)));
        } else {
            profit = max((prices[idx] - fee + solveMem(idx+1, true, prices, dp, fee)),
                        (0 + solveMem(idx+1, false, prices, dp, fee)));
        }

        return dp[idx][isBuy] = profit;
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        
        n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));

        return solveMem(0, true, prices, dp, fee);
    }
};