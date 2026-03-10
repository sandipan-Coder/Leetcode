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

public:
    int rob(vector<int>& nums) {
        
        memset(dp, -1, sizeof(dp));
        return solveMem(0, nums);
    }
};