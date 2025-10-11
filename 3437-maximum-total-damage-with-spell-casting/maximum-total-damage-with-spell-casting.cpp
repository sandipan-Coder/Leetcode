class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {

        unordered_map<int,int> freq;
        for (int x : power) 
            freq[x]++;

        vector<int> vals;
        for (auto& [v, _] : freq) 
            vals.push_back(v);
        sort(vals.begin(), vals.end());

        int n = vals.size();
        vector<int> nxt(n);
        for (int i = 0; i < n; i++)
            nxt[i] = upper_bound(vals.begin(), vals.end(), vals[i] + 2) - vals.begin();

        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            long long gain = 1LL * vals[i] * freq[vals[i]];
            dp[i] = max(dp[i + 1], gain + dp[nxt[i]]);
        }

        return dp[0];
    }
};