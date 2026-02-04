class Solution {
    typedef long long ll;
    // int n;
    // vector<vector<ll>> dp;
/*
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
*/

public:
    ll maxSumTrionic(vector<int>& nums) {
        
        ll n = size(nums);
        ll i = 0;
        vector<vector<ll>> v;

        while(i < n){ // note-down the dec-trend indices
            int org = i;
            ll dec_sum = 0;

            while(i+1 < n && nums[i] > nums[i+1]){
                dec_sum += nums[i] * 1ll;
                i++;
            }

            if(i != org){
                
                dec_sum += nums[i];
                v.push_back({org, i, dec_sum});
            }

            i++;
        }


        ll ans = -1e18;

        for(vector<ll> t : v) {

            ll left = t[0]; 
            ll right = t[1];

            if ( left == 0 || right == n-1)  
                continue ;
            
            ll left_sum = -1e18;
            ll right_sum = -1e18;
            ll cur = 0;
            while(left - 1 >= 0 && nums[left - 1] < nums[left]){ // left-inc max
                cur += nums[left - 1] * 1ll;
                left_sum = max(left_sum, cur);
                left--;
            }

            cur = 0;
            while(right + 1 < n && nums[right] < nums[right+1]){ // right-inc max
                cur += nums[right + 1] * 1ll;
                right_sum = max(right_sum, cur);
                right++;
            }

            ll total_sum = left_sum + t[2] + right_sum; // t[2] : cur dec section sum
            ans = max(ans, total_sum);
        }

        return ans;
    }
};