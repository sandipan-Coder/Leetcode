class Solution {

    int n;
    int dp[21][4002];

private:

    int solve(int idx, int target, vector<int>& arr) {
        
        if(idx == n) {
            if(target == 0)
                return 1;
            else
                return 0;
        }
        
        if(dp[idx][target + 2000] != -1)
            return dp[idx][target + 2000];
        
        return dp[idx][target + 2000] = (solve(idx + 1, target - arr[idx], arr) + 
                solve(idx + 1, target + arr[idx], arr));
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, target, nums);
    }
};