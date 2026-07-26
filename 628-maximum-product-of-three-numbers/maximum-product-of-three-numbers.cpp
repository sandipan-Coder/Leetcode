class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();

        int mul1 = (nums[0] * nums[1] * nums[2]);
        int mul2 = (nums[0] * nums[n - 1] * nums[n - 2]);

        return max(mul1, mul2);
    }
};