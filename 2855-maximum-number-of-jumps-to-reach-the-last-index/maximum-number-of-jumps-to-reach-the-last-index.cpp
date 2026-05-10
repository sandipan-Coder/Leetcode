class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int> dp(n, 0);

        for(int i = n-2; i >= 0; i--){
            for(int j = i+1; j < n; j++) {

                if(abs(nums[j] - nums[i]) <= target && (dp[j] > 0 || j == n-1))
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        if(dp[0] == 0)
            return -1;
        
        return dp[0];
    }
};