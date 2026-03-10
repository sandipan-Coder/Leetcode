class Solution {
private:

    int dp[103];

    int solve(int idx, vector<int>& nums) {

        if(idx >= nums.size())
            return 0;
        
        int take = nums[idx] + solve(idx + 2, nums);
        int leave = solve(idx + 1, nums);
    
        return max(take, leave);
    }

    int solveMem(int idx, vector<int>& nums) {

        if(idx >= nums.size())
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int take = nums[idx] + solveMem(idx + 2, nums);
        int leave = solveMem(idx + 1, nums);
    
        return dp[idx] = max(take, leave);
    }

    int solveBottom(vector<int>& nums) {

        int n = nums.size();
        int dp1[103];
        memset(dp1, 0, sizeof(dp1));

        dp1[n - 1] = nums[n - 1];

        for(int idx = n-2; idx >= 0; idx--) {

            int take = nums[idx] + dp1[idx + 2];
            int leave = dp1[idx + 1];
        
            dp1[idx] = max(take, leave);
        }

        return dp1[0];
    }

public:
    int rob(vector<int>& nums) {
        
        /*
        memset(dp, -1, sizeof(dp));
        return solveMem(0, nums);
        */

        return solveBottom(nums);
    }
};