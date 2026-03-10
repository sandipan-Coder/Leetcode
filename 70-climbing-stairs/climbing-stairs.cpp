class Solution {
private:
    int dp[48];
    int solve(int steps, int &n) {

        if(steps > n)
            return 0;
        
        if(steps == n)
            return 1;
        
        if(dp[steps] != -1)
            return dp[steps];
        
        return dp[steps] = (solve(steps + 1, n) + solve(steps + 2, n));
    }

public:
    int climbStairs(int n) {
        
        memset(dp, -1, sizeof(dp));
        return solve(0, n);
    }
};