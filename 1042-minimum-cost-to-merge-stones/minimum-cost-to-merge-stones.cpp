class Solution {
private:

int solve(int idx, int len, int k, vector<int> &preSum, vector<vector<int>> &dp){
        
    if(idx >= len)        
        return 0;
    
    if(dp[idx][len] != -1)
        return dp[idx][len];
    
    int ans = INT_MAX;
    for(int i = idx; i < len; i += (k - 1)){
        
        ans = min (ans, solve(idx, i, k, preSum, dp) + 
                        solve(i+1, len, k, preSum, dp));
    }
    
    if((len - idx) % (k - 1) == 0)
        ans += preSum[len + 1] - preSum[idx];
    
    return dp[idx][len] = ans;
}

public:
    int mergeStones(vector<int>& stones, int k) {
        
        int n = stones.size();
        if((n - 1) % (k - 1))
            return -1;
            
        vector<int> preSum(n+1, 0);
        for(int i = 0; i < n; i++)
            preSum[i + 1] = preSum[i] + stones[i];
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return solve(0, n-1, k, preSum, dp);
    }
};