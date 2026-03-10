class Solution {

    int dp[103];
private:

    int solveMem(int idx, vector<int>& nums, int end) {

        if(idx > end)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int take = nums[idx] + solveMem(idx + 2, nums, end);
        int leave = solveMem(idx + 1, nums, end);
    
        return dp[idx] = max(take, leave);
    }

public:
    int rob(vector<int>& nums) {
    
        int n = nums.size();

        if(n == 1)
            return nums[0];
        
        if(n == 2)
            return max(nums[0], nums[1]);

        memset(dp, -1, sizeof(dp));
        int start0 = solveMem(0, nums, n-2);

        memset(dp, -1, sizeof(dp));
        int start1 = solveMem(1, nums, n-1);

        return max(start0, start1);
    }
};