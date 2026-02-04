class Solution {
    typedef long long ll;
    int n;
    vector<vector<ll>> dp;

private:

    ll solve(int idx, int trand, vector<int>& nums) {

        if(idx == n) {
            if(trand == 3)
                return 0;
            else 
                return LLONG_MIN / 2;
        }

        if(dp[idx][trand] != LLONG_MIN)
            return dp[idx][trand];
        

        ll take = LLONG_MIN / 2;
        ll skip = LLONG_MIN / 2;

        if(trand == 0)
            skip = solve(idx + 1, 0, nums);
        
        if(trand == 3)
            take = nums[idx];
        
        if(idx + 1 < n) {

            int curr = nums[idx];
            int next = nums[idx + 1];

            if(trand == 0 && next > curr)
                take = max(take, curr + solve(idx + 1, 1, nums));
            else if(trand == 1) {
                if(next > curr) 
                    take = max(take, curr + solve(idx + 1, 1, nums));
                else if(next < curr)
                    take = max(take, curr + solve(idx + 1, 2, nums));

            } else if(trand == 2) {
                if(next < curr)
                    take = max(take, curr + solve(idx + 1, 2, nums));
                else if(next > curr)
                    take = max(take, curr + solve(idx + 1, 3, nums));

            } else if(trand == 3 && next > curr)
                take = max(take, curr + solve(idx + 1, 3, nums));

        }
        
        return dp[idx][trand] = max(take, skip);
    }

public:
    ll maxSumTrionic(vector<int>& nums) {
        
        n = nums.size();
        dp.resize(n+1, vector<ll>(4, LLONG_MIN));

        return solve(0, 0, nums);  // solve(index, trand, array)
    }
};