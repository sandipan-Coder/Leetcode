class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(n == 1)
            return 0;

        int diff = INT_MAX;  // If store the minimum difference.

        sort(nums.begin(), nums.end());

        for(int i = 0; i+k-1 < n; i++)
            diff = min(diff, (nums[i + k - 1] - nums[i]));

        return diff;
    }
};