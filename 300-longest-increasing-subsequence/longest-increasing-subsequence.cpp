class Solution {
private:
    // Recursive Solution
    int solve(vector<int>& nums, int n, int idx, int lastIdx){

        if(idx >= n)
            return 0;
        
        // Include
        int include = 0;
        if(lastIdx == -1 || nums[idx] > nums[lastIdx])
           include =  1 + solve(nums, n, idx + 1, idx) ;
        
        int exclude = solve(nums, n, idx + 1, lastIdx);

        return max(include, exclude);
    }

    // Recursive + Memoization
    int solveMem(vector<int>& nums, int n, int idx, int lastIdx, vector<vector<int>> &dp){
        if(idx >= n)
            return 0;

        if(dp[idx][lastIdx + 1] != -1)
            return dp[idx][lastIdx + 1];
        // Include
        int include = 0;
        if(lastIdx == -1 || nums[idx] > nums[lastIdx])
           include =  1 + solveMem(nums, n, idx + 1, idx, dp) ;
        
        int exclude = solveMem(nums, n, idx + 1, lastIdx, dp);

        return dp[idx][lastIdx + 1] = max(include, exclude);
    }

    // Tabulation
    int solveTab(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        for(int idx = n-1; idx >= 0; idx--){
            for(int lastIdx = idx - 1; lastIdx >= -1; lastIdx--){
                int include = 0;
                if(lastIdx == -1 || nums[idx] > nums[lastIdx])
                    include =  1 + dp[idx + 1][idx + 1];
                
                int exclude = dp[idx + 1][lastIdx + 1];

                dp[idx][lastIdx + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    // Space Optimization
    int solveSpace(vector<int>& nums){
        int n = nums.size();
       vector<int>curr(n+1, 0);
       vector<int>next(n+1, 0);

        for(int idx = n-1; idx >= 0; idx--){
            for(int lastIdx = idx - 1; lastIdx >= -1; lastIdx--){
                int include = 0;
                if(lastIdx == -1 || nums[idx] > nums[lastIdx])
                    include =  1 + next[idx + 1];
                
                int exclude = next[lastIdx + 1];

                curr[lastIdx + 1] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }

    // Most Optimal Solution
    int solveOptimal(vector<int>& nums){
        int n = nums.size();
        vector<int>ans;
        ans.push_back(nums[0]);

        for(int i = 1; i < n; i++){
            if(nums[i] > ans.back())
                ans.push_back(nums[i]);
            else{

                int idx = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[idx] = nums[i];
            }
        }
        return ans.size();
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        // Recursive Solution
        /*
        return solve(nums, n, 0, -1);
        */

        // Recursive + Memoization
        /*
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return solveMem(nums, n, 0, -1, dp);
        */
        
        // Tabulation
        
        return solveTab(nums); 
        

        // Space Optimizaton
        /*
        return solveSpace(nums);
        */

        // Most Optimal Solution
        /*
        return solveOptimal(nums);
        */
    }
};