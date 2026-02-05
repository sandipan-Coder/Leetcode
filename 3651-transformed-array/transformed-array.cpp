class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1)
            return nums;

        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++) {

            int idx = (i + nums[i]) % n;
            ans[i] = (idx < 0) ? nums[n + idx] : nums[idx];
        }

        return ans;
    }
};