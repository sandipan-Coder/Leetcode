class Solution {
public:
    int distinctSubseqII(string s) {
        
        int n = s.length();
        const int MOD = 1e9 + 7;

        vector<int> dp(n+1, 0);
        vector<int> lastApare(26, -1);
        dp[0] = 1;

        for(int i = 1; i <= n; i++){
            dp[i] = (2 * dp[i - 1]) % MOD;

            if(lastApare[s[i - 1] - 'a'] != -1)
                dp[i] = (dp[i] - dp[lastApare[s[i - 1] - 'a']] + MOD) % MOD;
            
            lastApare[s[i - 1] - 'a'] = i-1;
        }

        return (dp[n] - 1 + MOD) % MOD;
    }
};