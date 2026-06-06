class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        int n = nums.size();
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++) {

            rightSum -= nums[i];
            ans[i] = abs(rightSum - leftSum);
            leftSum += nums[i];
        }

        return ans;
    }
};