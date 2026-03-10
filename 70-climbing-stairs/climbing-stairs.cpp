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

    int solveBottom(int n) {

        int dp1[48];
        memset(dp1, 0, sizeof(dp1));
        dp1[n] = 1;

        for(int i = n-1; i >= 0; i--)
            dp1[i] = dp1[i + 1] + dp1[i + 2];
        
        return dp1[0];
    }

public:
    int climbStairs(int n) {
        
        /*
        memset(dp, -1, sizeof(dp));
        return solve(0, n);
        */

        return solveBottom(n);
    }
};