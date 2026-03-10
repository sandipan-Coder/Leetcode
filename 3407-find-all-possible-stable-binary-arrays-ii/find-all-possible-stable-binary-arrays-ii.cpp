class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        
        int MOD = 1e9 + 7;
        int dp[1001][1001][2];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i <= min(zero, limit); i++)
            dp[i][0][0] = 1;
        

        for(int j = 0; j <= min(one, limit); j++)
            dp[0][j][1] = 1;
        
        for(int i = 0; i <= zero; i++) {
            for(int j = 0; j <= one; j++) {
                
                if(i == 0 || j == 0)
                    continue;
                
                // Explore # 1's
                dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % MOD;
                if(j - 1 >= limit)
                    dp[i][j][1] = (dp[i][j][1] - dp[i][j - 1 - limit][0] + MOD) % MOD;
                
                // Explore # 0's
                dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
                if(i - 1 >= limit)
                    dp[i][j][0] = (dp[i][j][0] - dp[i - 1 - limit][j][1] + MOD) % MOD;
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};