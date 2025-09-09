class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);

        dp[1] = 1;
        long long sharers = 0;  // people who can share secret today

        for (int day = 2; day <= n; day++) {
            // people who become eligible to share today
            if (day - delay >= 1) 
                sharers = (sharers + dp[day - delay]) % MOD;
            // people who forget today stop sharing
            if (day - forget >= 1) 
                sharers = (sharers - dp[day - forget] + MOD) % MOD;

            dp[day] = sharers;  // new learners today
        }

        long long ans = 0;
        // Sum people who still remember on day n
        for (int day = n - forget + 1; day <= n; day++) {
            if (day >= 1) 
                ans = (ans + dp[day]) % MOD;
        }

        return (int)ans;
    }
};